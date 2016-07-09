#ifndef __GPX_PARSER_H
#define __GPX_PARSER_H

#include <string>

#include <gdal/gdal_priv.h>
#include <gdal/cpl_conv.h>
#include <gdal/ogrsf_frmts.h>
#include <gdal/ogr_core.h>
#include <gdal/ogr_feature.h>
#include <gdal/ogr_geometry.h>

#include <osg/Geometry>
#include <osg/Geode>
#include <osg/LineWidth>
#include <osgUtil/Tessellator>
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgGA/TerrainManipulator>

// tdgr stands for ThreeDimensionGpxReader
namespace tdgr {

  class GpxParser {
    private:
     osg::Vec3Array * vertices;
     osg::Vec3 * getVec3FromFeature(OGRFeature * feat)  const;
     osg::Vec3 * getRelativeVec3(OGRFeature * feat, const osg::Vec3 * refvec) const;

     double getElevation(OGRFeature * feat) const;

    public:
     static const std::string GPX_ELE_FIELD;
     static const double xyfactor, zfactor;

     GpxParser(const char * path);
     osg::Vec3Array * const & getVertices() const;
     ~GpxParser();
  };
}


#endif // __GPX_PARSER_H
