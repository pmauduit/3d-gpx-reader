#include "gpx-parser.h"

namespace tdgr {

  const double GpxParser::xyfactor = 10.0E6f;
  const double GpxParser::zfactor = 210.0f;
  const std::string GpxParser::GPX_ELE_FIELD = "ele";
  /**
   * @returns the parsed vertices.
   */
  osg::Vec3Array * const & GpxParser::getVertices() const {
    return vertices;
  }

  /**
   * Returns the elevation as a double, or NAN if unavailable.
   *
   */
  double GpxParser::getElevation(OGRFeature * feat) const {
    int eleIdx = feat->GetFieldIndex(GpxParser::GPX_ELE_FIELD.c_str());
    if (eleIdx != -1) {
      OGRFieldDefn * field = feat->GetFieldDefnRef(eleIdx);
      OGRFieldType t = field->GetType();
      if (t == OFTReal) {
       OGRField * fvalue = feat->GetRawFieldRef(eleIdx);
       return fvalue->Real;
      }
    }
    return NAN;
  }


  osg::Vec3 * GpxParser::getVec3FromFeature(OGRFeature * feat) const {
    OGRGeometry * geom = feat->GetGeometryRef();
    double x = 0, y = 0, z;
    z = this->getElevation(feat);
    if (geom->getGeometryType() == wkbPoint) {
      OGRPoint * pt = (OGRPoint *) geom;
      x = pt->getX();
      y = pt->getY();
    } else {
      OGRPoint *centroid = new OGRPoint;
      geom->Centroid(centroid);
      x = centroid->getX();
      y = centroid->getY();
      delete centroid;
    }
    return new osg::Vec3(x, y, z);
  }

  osg::Vec3 * GpxParser::getRelativeVec3(OGRFeature * feat, const osg::Vec3 * refvec) const {
    osg::Vec3 * pt = this->getVec3FromFeature(feat);
    for (unsigned int i = 0 ; i < 3 ; ++i) {
      (*pt)[i] -= (*refvec)[i];
      (*pt)[i] *= i == 2 ? zfactor : xyfactor;
    }
    return pt;
  }
  /**
   * @path a string which represents the path to the GPX file
   */
  GpxParser::GpxParser(const char * path) {

    GDALDataset * dataset = (GDALDataset *) GDALOpenEx(path, GDAL_OF_VECTOR | GDAL_OF_READONLY,
                                                       NULL, NULL, NULL);
    if(dataset == NULL)
    {
      fprintf(stderr, "Error opening GPX file %s\n", path);
      return;
    }

    vertices = new osg::Vec3Array;
    for (int i = 0 ; i < dataset->GetLayerCount() ; ++i) {
      OGRLayer * layer = dataset->GetLayer(i);
      OGRFeature * feat =  layer->GetNextFeature();

      osg::Vec3 * refpt = NULL;
      osg::Vec3 * currentpt = NULL;
      unsigned long numfeat = 0;

      while (feat != NULL) {
        if (numfeat == 0) {
          refpt = getVec3FromFeature(feat);
        }
        else {
          // skip 100 features
          //if (numfeat % 100 != 0) {
          //  numfeat++;
          //  OGRFeature::DestroyFeature(feat);
          //  feat = layer->GetNextFeature();
          //  continue;
          //}
          currentpt = getRelativeVec3(feat, refpt);
          //dump_point3d_as_osg(currentpt, numfeat);
          vertices->push_back(*currentpt);
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
  };

  GpxParser::~GpxParser() {
  };
}

