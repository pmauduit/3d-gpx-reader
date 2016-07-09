#include <osg/Geometry>
#include <osg/Geode>
#include <osg/LineWidth>
#include <osgUtil/Tessellator>
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgGA/TerrainManipulator>

#include <gdal/gdal_priv.h>
#include <gdal/cpl_conv.h>
#include <gdal/ogrsf_frmts.h>
#include <gdal/ogr_feature.h>

#include "gpx-parser.h"

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "Usage: %s <trace.gpx>\n", argv[0]);
    return 0;
  }

  GDALAllRegister();

  tdgr::GpxParser parser = tdgr::GpxParser(argv[1]);
  osg::Vec3Array * vertices = parser.getVertices();
  osg::ref_ptr<osg::Geometry> polygon = new osg::Geometry;

  polygon->setVertexArray(vertices);
  osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
  (*colors)[0].set(0.0f, 0.0f, 1.0f, 1.0f);

  osg::ref_ptr<osg::Geometry> border = new osg::Geometry;
  border->setVertexArray(vertices);
  border->setColorArray(colors.get());
  border->setColorBinding(osg::Geometry::BIND_OVERALL);

  for (unsigned int i = 0 ; i < vertices->size(); i += 2) {
    if (i + 4 >= vertices->size())
      break;
    polygon->addPrimitiveSet(new osg::DrawArrays(GL_POLYGON,  i, 4));
    border->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, i, 4));
  }
  border->getOrCreateStateSet()->setAttribute(new osg::LineWidth(5.0f));

  // creates a bounding box around the trace
  double minx = 0, miny = 0, minz = 0, maxx = 0, maxy = 0, maxz = 0;
  for (unsigned int i = 0 ; i < vertices->size(); ++i) {
    osg::Vec3 currentvec3 = (* vertices)[i];
    if (maxx < currentvec3.x()) maxx = currentvec3.x();
    if (maxy < currentvec3.y()) maxy = currentvec3.y();
    if (maxz < currentvec3.z()) maxz = currentvec3.z();
    if (minx > currentvec3.x()) minx = currentvec3.x();
    if (miny > currentvec3.y()) miny = currentvec3.y();
    if (minz > currentvec3.z()) minz = currentvec3.z();
  }
  fprintf(stdout, "minx: %f, miny,: %f, minz: %f, maxx: %f, maxy: %f, maxz: %f\n",
          minx,miny,minz,maxx,maxy,maxz);

  osg::ref_ptr<osg::Vec3Array> bbox = new osg::Vec3Array;
  bbox->push_back(osg::Vec3(minx, miny, minz)); // 0
  bbox->push_back(osg::Vec3(maxx, miny, minz)); // 1
  bbox->push_back(osg::Vec3(maxx, miny, maxz)); // 2
  bbox->push_back(osg::Vec3(minx, miny, maxz)); // 3
  bbox->push_back(osg::Vec3(maxx, maxy, minz)); // 4
  bbox->push_back(osg::Vec3(maxx, maxy, maxz)); // 5
  bbox->push_back(osg::Vec3(minx, maxy, maxz)); // 6
  bbox->push_back(osg::Vec3(minx, maxy, minz)); // 7
  osg::ref_ptr<osg::Geometry> boxborder = new osg::Geometry;
  boxborder->setVertexArray(bbox.get());
  osg::ref_ptr<osg::Vec4Array> bboxcolors = new osg::Vec4Array(1);
  (*bboxcolors)[0].set(0.0f, 0.0f, 0.0f, 1.0f);
  boxborder->setColorArray(bboxcolors.get());
  boxborder->setColorBinding(osg::Geometry::BIND_OVERALL);
  // face 1
  osg::DrawElementsUInt* bbf1 = 
               new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP, 0);
  bbf1->push_back(0);
  bbf1->push_back(1);
  bbf1->push_back(2);
  bbf1->push_back(3);
  // face 2
  osg::DrawElementsUInt* bbf2 = 
               new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP, 0);
  bbf2->push_back(1);
  bbf2->push_back(4);
  bbf2->push_back(5);
  bbf2->push_back(2);
  // face 3
  osg::DrawElementsUInt* bbf3 = 
               new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP, 0);
  bbf3->push_back(4);
  bbf3->push_back(5);
  bbf3->push_back(6);
  bbf3->push_back(7);
  // face 4
  osg::DrawElementsUInt* bbf4 = 
               new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP, 0);
  bbf4->push_back(0);
  bbf4->push_back(7);
  bbf4->push_back(6);
  bbf4->push_back(3);
  // face 5
  osg::DrawElementsUInt* bbf5 = 
               new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP, 0);
  bbf5->push_back(0);
  bbf5->push_back(1);
  bbf5->push_back(4);
  bbf5->push_back(7);
  // face 6
  osg::DrawElementsUInt* bbf6 = 
               new osg::DrawElementsUInt(osg::PrimitiveSet::LINE_LOOP, 0);
  bbf6->push_back(3);
  bbf6->push_back(2);
  bbf6->push_back(5);
  bbf6->push_back(6);

  boxborder->addPrimitiveSet(bbf1);
  boxborder->addPrimitiveSet(bbf2);
  boxborder->addPrimitiveSet(bbf3);
  boxborder->addPrimitiveSet(bbf4);
  boxborder->addPrimitiveSet(bbf5);
  boxborder->addPrimitiveSet(bbf6);


  osg::ref_ptr<osg::Geode> geode = new osg::Geode;
  geode->addDrawable(polygon.get());
  geode->addDrawable(border.get());
  geode->addDrawable(boxborder.get());
  osg::ref_ptr<osg::Group> root = new osg::Group;
  root->addChild(geode.get());
  osgViewer::Viewer viewer;
  viewer.setSceneData(root.get());
  viewer.setCameraManipulator(new osgGA::TerrainManipulator());
  return viewer.run();
}
