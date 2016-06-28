#include <gdal/gdal_priv.h>
#include <gdal/cpl_conv.h>
#include <gdal/ogrsf_frmts.h>
#include <gdal/ogr_feature.h>

#define GPX_ELE_FIELD "ele"

// 1.5*10^-6 ~~ 3m
// Adding / substracting half on coordinates
// to extrude a surface.
static double offset = 0.0000015 / 2.0;

static double xyfactor = 10.0E6f;
static double zfactor = 210.0f;


class point3d {
 public:
  double x;
  double y;
  double z;
};

/**
 * Dumps some info about a feature, was used for runtime-debugging purposes.
 *
 */
void dump_feature(OGRFeatureH feat) {
  fprintf(stdout, "Feature @0x%x\n", feat);
  for (int i = 0; i < OGR_F_GetFieldCount(feat) ; ++i) {
    OGRFieldDefnH field = OGR_F_GetFieldDefnRef(feat, i);
    fprintf(stdout, "\tField %s\n", OGR_Fld_GetNameRef(field));
  }
  int eleIdx = OGR_F_GetFieldIndex(feat, GPX_ELE_FIELD);
  if (eleIdx != -1) {
    OGRFieldDefnH field = OGR_F_GetFieldDefnRef(feat, eleIdx);
    OGRFieldType t = OGR_Fld_GetType(field);
    if (t == OFTReal) {
     OGRField * fvalue = OGR_F_GetRawFieldRef(feat, eleIdx);
     printf("ele: %f\n", fvalue->Real);
    }
    fprintf(stdout, "field type: %d\n", t);
  }
}

/**
 * Returns the elevation as a double, or NAN if unavailable.
 *
 */
double get_ele(OGRFeatureH feat) {
  int eleIdx = OGR_F_GetFieldIndex(feat, GPX_ELE_FIELD);
  if (eleIdx != -1) {
    OGRFieldDefnH field = OGR_F_GetFieldDefnRef(feat, eleIdx);
    OGRFieldType t = OGR_Fld_GetType(field);
    if (t == OFTReal) {
     OGRField * fvalue = OGR_F_GetRawFieldRef(feat, eleIdx);
     return fvalue->Real;
    }
  }
  return NAN;
}

/**
 * Dumps the geometry of the given feature.
 * Used when rutime-debugging / coding.
 */
void dump_geometry_info(OGRFeatureH feat) {
  OGRGeometryH geom = OGR_F_GetGeometryRef(feat);
  double x,y,z;
  fprintf(stdout, "points count in the Geom: %d\n", OGR_G_GetPointCount(geom));
  if (OGR_G_GetPointCount(geom) == 1) {
    x = OGR_G_GetX(geom, 0);
    y = OGR_G_GetY(geom, 0);
    z = OGR_G_GetZ(geom, 0);
    fprintf(stdout,"x: %f, y: %f, z: %f\n", x,y,z);
  }
}
/**
 * Dumps the vertices as OpenSceneGraph compatible C++ code.
 *
 */
void dump_as_osg(OGRFeatureH feat, int current) {
  OGRGeometryH geom = OGR_F_GetGeometryRef(feat);
  double x,y,z;
  if (OGR_G_GetPointCount(geom) == 1) {
    x = OGR_G_GetX(geom, 0);
    y = OGR_G_GetY(geom, 0);
    z = get_ele(feat);
    double x1 = x - offset;
    double x2 = x + offset;
    double y1 = y - offset;
    double y2 = y + offset;

    fprintf(stdout,"(*vertices)[%d].set(%ff, %ff, %ff);\n", current * 2,x1,y1,z);
    fprintf(stdout,"(*vertices)[%d].set(%ff, %ff, %ff);\n", current * 2 + 1,x2,y2,z);
  }
}

void dump_point3d_as_osg(point3d * point, int current) {
    double x1 = point->x - offset;
    double x2 = point->x + offset;
    double y1 = point->y - offset;
    double y2 = point->y + offset;


    fprintf(stdout,"vertices->push_back(osg::Vec3(%ff, %ff, %ff));\n",x1,y1, point->z);
    fprintf(stdout,"vertices->push_back(osg::Vec3(%ff, %ff, %ff));\n",x2,y2, point->z);
}

/**
 * Allocates a point3d from a given feature
 * It is the caller's responsability to free the returned pointer
 */
point3d * get_point3d_from_feature(OGRFeatureH feat) {
  OGRGeometryH geom = OGR_F_GetGeometryRef(feat);
  point3d * point = new point3d;
  double x,y,z;
  if (OGR_G_GetPointCount(geom) == 1) {
    x = OGR_G_GetX(geom, 0);
    y = OGR_G_GetY(geom, 0);
    z = get_ele(feat);

    point->x = x;
    point->y = y;
    point->z = z;
  }
  return point;
}

/**
 * Calculates a point3d given a feature and
 * an origin.
 * Still requires that the caller free() the memory afterwards.
 */
point3d * get_point3d_relative(OGRFeatureH feat, point3d * origin) {
    point3d * point = get_point3d_from_feature(feat);
    point->x -= origin->x;
    point->y -= origin->y;
    point->z -= origin->z;

    point->x *= xyfactor;
    point->y *= xyfactor;
    point->z *= zfactor;

    return point;
}


int main2 (int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "Usage %s <file.gpx>\n", argv[0]);
    return 0;
  }

  GDALAllRegister();

  GDALDataset * dataset = (GDALDataset *) GDALOpenEx(argv[1], GDAL_OF_VECTOR | GDAL_OF_READONLY,
      NULL, NULL, NULL);

  if(dataset == NULL)
  {
    fprintf(stderr, "Error opening GPX file %s\n", argv[1]);
    abort();
  }

  for (int i = 0 ; i < dataset->GetLayerCount() ; ++i) {
    OGRLayer * layer = dataset->GetLayer(i);
    OGRFeature * feat =  layer->GetNextFeature();

    point3d * refpt = NULL; point3d * currentpt = NULL;
    unsigned long numfeat = 0;

    while (feat != NULL) {

      if (numfeat == 0) {
        refpt = get_point3d_from_feature(feat);
        point3d origin;
        origin.x = 0.0f;
        origin.y = 0.0f;
        origin.z = 0.0f;
        dump_point3d_as_osg(&origin, numfeat);
      }
      else {
        // skip 100 features
        if (numfeat % 100 != 0) {
          numfeat++;
          OGRFeature::DestroyFeature(feat);
          feat = layer->GetNextFeature();
          continue;
        }
        currentpt = get_point3d_relative(feat, refpt);
        dump_point3d_as_osg(currentpt, numfeat);
        if (currentpt != NULL) {
          delete currentpt;
          currentpt = NULL;
        }
      }
      // Next feature
      numfeat++;
      OGRFeature::DestroyFeature(feat);
      feat = layer->GetNextFeature();
    }
    if (refpt != NULL) {
      delete refpt;
      refpt = NULL;
    }
  }

  delete dataset;
  return 0;
}
