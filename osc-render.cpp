#include <osg/Geometry>
#include <osg/Geode>
#include <osg/LineWidth>
#include <osgUtil/Tessellator>
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgGA/TerrainManipulator>

osg::ref_ptr<osg::Vec3Array> generate_trace_vertices() {
  osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(24);

  (*vertices)[0].set(-0.000001f, -0.000001f, 0.000000f);
  (*vertices)[1].set(0.000001f, 0.000001f, 0.000000f);
  (*vertices)[2].set(179.372999f, 2377.107999f, 39.890000f);
  (*vertices)[3].set(179.373001f, 2377.108001f, 39.890000f);
  (*vertices)[4].set(-153.389001f, 2451.706999f, 44.700000f);
  (*vertices)[5].set(-153.388999f, 2451.707001f, 44.700000f);
  (*vertices)[6].set(6525.311999f, 1699.849999f, 50.460000f);
  (*vertices)[7].set(6525.312001f, 1699.850001f, 50.460000f);
  (*vertices)[8].set(10992.865999f, 2289.097999f, 54.310000f);
  (*vertices)[9].set(10992.866001f, 2289.098001f, 54.310000f);
  (*vertices)[10].set(24683.027999f, 2143.252999f, 66.330000f);
  (*vertices)[11].set(24683.028001f, 2143.253001f, 66.330000f);
  (*vertices)[12].set(38382.410999f, 1207.831999f, 75.940000f);
  (*vertices)[13].set(38382.411001f, 1207.832001f, 75.940000f);
  (*vertices)[14].set(53222.570999f, 1931.189999f, 93.720000f);
  (*vertices)[15].set(53222.571001f, 1931.190001f, 93.720000f);
  (*vertices)[16].set(65243.057999f, -226.311001f, 114.390000f);
  (*vertices)[17].set(65243.058001f, -226.310999f, 114.390000f);
  (*vertices)[18].set(73522.701999f, 188.592999f, 136.500000f);
  (*vertices)[19].set(73522.702001f, 188.593001f, 136.500000f);
  (*vertices)[20].set(71119.609999f, -9445.567001f, 158.130000f);
  (*vertices)[21].set(71119.610001f, -9445.566999f, 158.130000f);
  (*vertices)[22].set(63419.155999f, -17263.368001f, 177.360000f);
  (*vertices)[23].set(63419.156001f, -17263.367999f, 177.360000f);
  return vertices;
}
int main(void) {

  osg::ref_ptr<osg::Vec3Array> vertices = generate_trace_vertices();
  osg::ref_ptr<osg::Geometry> polygon = new osg::Geometry;

  polygon->setVertexArray(vertices.get());
  osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(1);
  (*colors)[0].set(0.0f, 0.0f, 1.0f, 1.0f);

  osg::ref_ptr<osg::Geometry> border = new osg::Geometry;
  border->setVertexArray(vertices.get());
  border->setColorArray(colors.get());
  border->setColorBinding(osg::Geometry::BIND_OVERALL);

  std::cout << vertices->size() << std::endl;
  for (int i = 0 ; i < vertices->size(); i += 2) {
    if (i + 4 >= vertices->size())
      break;
    polygon->addPrimitiveSet(new osg::DrawArrays(GL_POLYGON,  i, 4));
    border->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, i, 4));
  }
  border->getOrCreateStateSet()->setAttribute(new osg::LineWidth(5.0f));

  osg::ref_ptr<osg::Geode> geode = new osg::Geode;
  geode->addDrawable(polygon.get());
  geode->addDrawable(border.get());
  osg::ref_ptr<osg::Group> root = new osg::Group;
  root->addChild(geode.get());
  osgViewer::Viewer viewer;
  viewer.setSceneData(root.get());
  viewer.setCameraManipulator(new osgGA::TerrainManipulator());
  return viewer.run();
}
