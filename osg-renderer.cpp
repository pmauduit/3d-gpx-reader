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
  osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

  vertices->push_back(osg::Vec3(-0.000001f, -0.000001f, 0.000000f));
  vertices->push_back(osg::Vec3(0.000001f, 0.000001f, 0.000000f));
  vertices->push_back(osg::Vec3(-0.000001f, -0.000001f, 0.000000f));
  vertices->push_back(osg::Vec3(0.000001f, 0.000001f, 0.000000f));
  vertices->push_back(osg::Vec3(179.372999f, 2377.107999f, 39.890000f));
  vertices->push_back(osg::Vec3(179.373001f, 2377.108001f, 39.890000f));
  vertices->push_back(osg::Vec3(-153.389001f, 2451.706999f, 44.700000f));
  vertices->push_back(osg::Vec3(-153.388999f, 2451.707001f, 44.700000f));
  vertices->push_back(osg::Vec3(6525.311999f, 1699.849999f, 50.460000f));
  vertices->push_back(osg::Vec3(6525.312001f, 1699.850001f, 50.460000f));
  vertices->push_back(osg::Vec3(10992.865999f, 2289.097999f, 54.310000f));
  vertices->push_back(osg::Vec3(10992.866001f, 2289.098001f, 54.310000f));
  vertices->push_back(osg::Vec3(24683.027999f, 2143.252999f, 66.330000f));
  vertices->push_back(osg::Vec3(24683.028001f, 2143.253001f, 66.330000f));
  vertices->push_back(osg::Vec3(38382.410999f, 1207.831999f, 75.940000f));
  vertices->push_back(osg::Vec3(38382.411001f, 1207.832001f, 75.940000f));
  vertices->push_back(osg::Vec3(53222.570999f, 1931.189999f, 93.720000f));
  vertices->push_back(osg::Vec3(53222.571001f, 1931.190001f, 93.720000f));
  vertices->push_back(osg::Vec3(65243.057999f, -226.311001f, 114.390000f));
  vertices->push_back(osg::Vec3(65243.058001f, -226.310999f, 114.390000f));
  vertices->push_back(osg::Vec3(73522.701999f, 188.592999f, 136.500000f));
  vertices->push_back(osg::Vec3(73522.702001f, 188.593001f, 136.500000f));
  vertices->push_back(osg::Vec3(71119.609999f, -9445.567001f, 158.130000f));
  vertices->push_back(osg::Vec3(71119.610001f, -9445.566999f, 158.130000f));
  vertices->push_back(osg::Vec3(63419.155999f, -17263.368001f, 177.360000f));
  vertices->push_back(osg::Vec3(63419.156001f, -17263.367999f, 177.360000f));
  vertices->push_back(osg::Vec3(71988.813999f, -19768.719001f, 196.580000f));
  vertices->push_back(osg::Vec3(71988.814001f, -19768.718999f, 196.580000f));
  vertices->push_back(osg::Vec3(77209.900999f, -21420.792001f, 205.240000f));
  vertices->push_back(osg::Vec3(77209.901001f, -21420.791999f, 205.240000f));
  vertices->push_back(osg::Vec3(81445.276999f, -20681.508001f, 218.210000f));
  vertices->push_back(osg::Vec3(81445.277001f, -20681.507999f, 218.210000f));
  vertices->push_back(osg::Vec3(90579.036999f, -21392.293001f, 240.810000f));
  vertices->push_back(osg::Vec3(90579.037001f, -21392.292999f, 240.810000f));
  vertices->push_back(osg::Vec3(99741.294999f, -19128.341001f, 259.070000f));
  vertices->push_back(osg::Vec3(99741.295001f, -19128.340999f, 259.070000f));
  vertices->push_back(osg::Vec3(108765.251999f, -11049.025001f, 273.490000f));
  vertices->push_back(osg::Vec3(108765.252001f, -11049.024999f, 273.490000f));
  vertices->push_back(osg::Vec3(109685.584999f, -17783.046001f, 290.310000f));
  vertices->push_back(osg::Vec3(109685.585001f, -17783.045999f, 290.310000f));
  vertices->push_back(osg::Vec3(122701.003999f, -20912.848001f, 310.980000f));
  vertices->push_back(osg::Vec3(122701.004001f, -20912.847999f, 310.980000f));
  vertices->push_back(osg::Vec3(135880.708999f, -22738.427001f, 334.050000f));
  vertices->push_back(osg::Vec3(135880.709001f, -22738.426999f, 334.050000f));
  vertices->push_back(osg::Vec3(147402.472999f, -24382.956001f, 356.160000f));
  vertices->push_back(osg::Vec3(147402.473001f, -24382.955999f, 356.160000f));
  vertices->push_back(osg::Vec3(162897.258999f, -27871.504001f, 360.010000f));
  vertices->push_back(osg::Vec3(162897.259001f, -27871.503999f, 360.010000f));
  vertices->push_back(osg::Vec3(170813.127999f, -35703.555001f, 367.220000f));
  vertices->push_back(osg::Vec3(170813.128001f, -35703.554999f, 367.220000f));
  vertices->push_back(osg::Vec3(175613.443999f, -38088.206001f, 373.950000f));
  vertices->push_back(osg::Vec3(175613.444001f, -38088.205999f, 373.950000f));
  vertices->push_back(osg::Vec3(184885.505999f, -43824.781001f, 388.370000f));
  vertices->push_back(osg::Vec3(184885.506001f, -43824.780999f, 388.370000f));
  vertices->push_back(osg::Vec3(193271.599999f, -47606.696001f, 400.380000f));
  vertices->push_back(osg::Vec3(193271.600001f, -47606.695999f, 400.380000f));
  vertices->push_back(osg::Vec3(205893.069999f, -54161.344001f, 420.570000f));
  vertices->push_back(osg::Vec3(205893.070001f, -54161.343999f, 420.570000f));
  vertices->push_back(osg::Vec3(220718.141999f, -55754.744001f, 439.800000f));
  vertices->push_back(osg::Vec3(220718.142001f, -55754.743999f, 439.800000f));
  vertices->push_back(osg::Vec3(236624.478999f, -54359.157001f, 454.700000f));
  vertices->push_back(osg::Vec3(236624.479001f, -54359.156999f, 454.700000f));
  vertices->push_back(osg::Vec3(244863.889999f, -60131.773001f, 474.410000f));
  vertices->push_back(osg::Vec3(244863.890001f, -60131.772999f, 474.410000f));
  vertices->push_back(osg::Vec3(245805.177999f, -70150.662001f, 487.860000f));
  vertices->push_back(osg::Vec3(245805.178001f, -70150.661999f, 487.860000f));
  vertices->push_back(osg::Vec3(255000.963999f, -72909.985001f, 494.590000f));
  vertices->push_back(osg::Vec3(255000.964001f, -72909.984999f, 494.590000f));
  vertices->push_back(osg::Vec3(266863.870999f, -75352.471001f, 515.740000f));
  vertices->push_back(osg::Vec3(266863.871001f, -75352.470999f, 515.740000f));
  vertices->push_back(osg::Vec3(275558.419999f, -77020.470001f, 532.080000f));
  vertices->push_back(osg::Vec3(275558.420001f, -77020.469999f, 532.080000f));
  vertices->push_back(osg::Vec3(286018.196999f, -78183.040001f, 549.870000f));
  vertices->push_back(osg::Vec3(286018.197001f, -78183.039999f, 549.870000f));
  vertices->push_back(osg::Vec3(286482.553999f, -79092.477001f, 551.790000f));
  vertices->push_back(osg::Vec3(286482.554001f, -79092.476999f, 551.790000f));
  vertices->push_back(osg::Vec3(293592.921999f, -82813.203001f, 571.020000f));
  vertices->push_back(osg::Vec3(293592.922001f, -82813.202999f, 571.020000f));
  vertices->push_back(osg::Vec3(301324.389999f, -84254.053001f, 592.170000f));
  vertices->push_back(osg::Vec3(301324.390001f, -84254.052999f, 592.170000f));
  vertices->push_back(osg::Vec3(309101.119999f, -86525.548001f, 615.240000f));
  vertices->push_back(osg::Vec3(309101.120001f, -86525.547999f, 615.240000f));
  vertices->push_back(osg::Vec3(319024.454999f, -89484.360001f, 636.390000f));
  vertices->push_back(osg::Vec3(319024.455001f, -89484.359999f, 636.390000f));
  vertices->push_back(osg::Vec3(327427.312999f, -93604.066001f, 651.770000f));
  vertices->push_back(osg::Vec3(327427.313001f, -93604.065999f, 651.770000f));
  vertices->push_back(osg::Vec3(332535.244999f, -99950.843001f, 671.000000f));
  vertices->push_back(osg::Vec3(332535.245001f, -99950.842999f, 671.000000f));
  vertices->push_back(osg::Vec3(338512.379999f, -106994.156001f, 680.610000f));
  vertices->push_back(osg::Vec3(338512.380001f, -106994.155999f, 680.610000f));
  vertices->push_back(osg::Vec3(342663.935999f, -109906.029001f, 679.650000f));
  vertices->push_back(osg::Vec3(342663.936001f, -109906.028999f, 679.650000f));
  vertices->push_back(osg::Vec3(349753.349999f, -112244.580001f, 681.570000f));
  vertices->push_back(osg::Vec3(349753.350001f, -112244.579999f, 681.570000f));
  vertices->push_back(osg::Vec3(363278.388999f, -116650.108001f, 702.720000f));
  vertices->push_back(osg::Vec3(363278.389001f, -116650.107999f, 702.720000f));
  vertices->push_back(osg::Vec3(371110.438999f, -121058.151001f, 723.870000f));
  vertices->push_back(osg::Vec3(371110.439001f, -121058.150999f, 723.870000f));
  vertices->push_back(osg::Vec3(377018.842999f, -125230.663001f, 746.460000f));
  vertices->push_back(osg::Vec3(377018.843001f, -125230.662999f, 746.460000f));
  vertices->push_back(osg::Vec3(385570.059999f, -129585.061001f, 764.720000f));
  vertices->push_back(osg::Vec3(385570.060001f, -129585.060999f, 764.720000f));
  vertices->push_back(osg::Vec3(388736.743999f, -133743.323001f, 764.240000f));
  vertices->push_back(osg::Vec3(388736.744001f, -133743.322999f, 764.240000f));
  vertices->push_back(osg::Vec3(396553.705999f, -139758.177001f, 754.150000f));
  vertices->push_back(osg::Vec3(396553.706001f, -139758.176999f, 754.150000f));
  vertices->push_back(osg::Vec3(407228.059999f, -147528.201001f, 737.330000f));
  vertices->push_back(osg::Vec3(407228.060001f, -147528.200999f, 737.330000f));
  vertices->push_back(osg::Vec3(412333.476999f, -154161.640001f, 710.410000f));
  vertices->push_back(osg::Vec3(412333.477001f, -154161.639999f, 710.410000f));
  vertices->push_back(osg::Vec3(417181.569999f, -160495.844001f, 685.900000f));
  vertices->push_back(osg::Vec3(417181.570001f, -160495.843999f, 685.900000f));
  vertices->push_back(osg::Vec3(419577.955999f, -163154.583001f, 673.400000f));
  vertices->push_back(osg::Vec3(419577.956001f, -163154.582999f, 673.400000f));
  vertices->push_back(osg::Vec3(419643.334999f, -163219.962001f, 672.920000f));
  vertices->push_back(osg::Vec3(419643.335001f, -163219.961999f, 672.920000f));
  vertices->push_back(osg::Vec3(420227.553999f, -163636.543001f, 673.880000f));
  vertices->push_back(osg::Vec3(420227.554001f, -163636.542999f, 673.880000f));
  vertices->push_back(osg::Vec3(418903.212999f, -168757.048001f, 679.650000f));
  vertices->push_back(osg::Vec3(418903.213001f, -168757.047999f, 679.650000f));
  vertices->push_back(osg::Vec3(420634.075999f, -174832.251001f, 679.650000f));
  vertices->push_back(osg::Vec3(420634.076001f, -174832.250999f, 679.650000f));
  vertices->push_back(osg::Vec3(421706.959999f, -176863.186001f, 693.590000f));
  vertices->push_back(osg::Vec3(421706.960001f, -176863.185999f, 693.590000f));
  vertices->push_back(osg::Vec3(421708.635999f, -177300.721001f, 695.030000f));
  vertices->push_back(osg::Vec3(421708.636001f, -177300.720999f, 695.030000f));
  vertices->push_back(osg::Vec3(422605.499999f, -179397.874001f, 706.560000f));
  vertices->push_back(osg::Vec3(422605.500001f, -179397.873999f, 706.560000f));
  vertices->push_back(osg::Vec3(427356.361999f, -182779.133001f, 726.270000f));
  vertices->push_back(osg::Vec3(427356.362001f, -182779.132999f, 726.270000f));
  vertices->push_back(osg::Vec3(433344.393999f, -185176.358001f, 738.290000f));
  vertices->push_back(osg::Vec3(433344.394001f, -185176.357999f, 738.290000f));
  vertices->push_back(osg::Vec3(437184.143999f, -191772.077001f, 756.070000f));
  vertices->push_back(osg::Vec3(437184.144001f, -191772.076999f, 756.070000f));
  vertices->push_back(osg::Vec3(438148.900999f, -193095.580001f, 768.570000f));
  vertices->push_back(osg::Vec3(438148.901001f, -193095.579999f, 768.570000f));
  vertices->push_back(osg::Vec3(441747.251999f, -192561.653001f, 790.200000f));
  vertices->push_back(osg::Vec3(441747.252001f, -192561.652999f, 790.200000f));
  vertices->push_back(osg::Vec3(445470.492999f, -192290.079001f, 806.540000f));
  vertices->push_back(osg::Vec3(445470.493001f, -192290.078999f, 806.540000f));
  vertices->push_back(osg::Vec3(451197.847999f, -193401.519001f, 820.960000f));
  vertices->push_back(osg::Vec3(451197.848001f, -193401.518999f, 820.960000f));
  vertices->push_back(osg::Vec3(454735.010999f, -194761.064001f, 832.500000f));
  vertices->push_back(osg::Vec3(454735.011001f, -194761.063999f, 832.500000f));
  vertices->push_back(osg::Vec3(460725.556999f, -196241.308001f, 850.280000f));
  vertices->push_back(osg::Vec3(460725.557001f, -196241.307999f, 850.280000f));
  vertices->push_back(osg::Vec3(462800.915999f, -196660.403001f, 861.820000f));
  vertices->push_back(osg::Vec3(462800.916001f, -196660.402999f, 861.820000f));
  vertices->push_back(osg::Vec3(465968.437999f, -195354.503001f, 880.080000f));
  vertices->push_back(osg::Vec3(465968.438001f, -195354.502999f, 880.080000f));
  vertices->push_back(osg::Vec3(467916.391999f, -194114.819001f, 898.830000f));
  vertices->push_back(osg::Vec3(467916.392001f, -194114.818999f, 898.830000f));
  vertices->push_back(osg::Vec3(467997.695999f, -192996.673001f, 905.560000f));
  vertices->push_back(osg::Vec3(467997.696001f, -192996.672999f, 905.560000f));
  vertices->push_back(osg::Vec3(471505.522999f, -193942.990001f, 921.420000f));
  vertices->push_back(osg::Vec3(471505.523001f, -193942.989999f, 921.420000f));
  vertices->push_back(osg::Vec3(471177.789999f, -195021.741001f, 925.740000f));
  vertices->push_back(osg::Vec3(471177.790001f, -195021.740999f, 925.740000f));
  vertices->push_back(osg::Vec3(471525.638999f, -196716.562001f, 938.720000f));
  vertices->push_back(osg::Vec3(471525.639001f, -196716.561999f, 938.720000f));
  vertices->push_back(osg::Vec3(473730.079999f, -198970.456001f, 952.180000f));
  vertices->push_back(osg::Vec3(473730.080001f, -198970.455999f, 952.180000f));
  vertices->push_back(osg::Vec3(474609.340999f, -200173.259001f, 953.140000f));
  vertices->push_back(osg::Vec3(474609.341001f, -200173.258999f, 953.140000f));
  vertices->push_back(osg::Vec3(477403.029999f, -201512.687001f, 962.270000f));
  vertices->push_back(osg::Vec3(477403.030001f, -201512.686999f, 962.270000f));
  vertices->push_back(osg::Vec3(481272.954999f, -202618.260001f, 975.730000f));
  vertices->push_back(osg::Vec3(481272.955001f, -202618.259999f, 975.730000f));
  vertices->push_back(osg::Vec3(483099.370999f, -203502.551001f, 996.400000f));
  vertices->push_back(osg::Vec3(483099.371001f, -203502.550999f, 996.400000f));
  vertices->push_back(osg::Vec3(486242.584999f, -206230.022001f, 1008.900000f));
  vertices->push_back(osg::Vec3(486242.585001f, -206230.021999f, 1008.900000f));
  vertices->push_back(osg::Vec3(489306.170999f, -208607.130001f, 1019.470000f));
  vertices->push_back(osg::Vec3(489306.171001f, -208607.129999f, 1019.470000f));
  vertices->push_back(osg::Vec3(489291.082999f, -209156.144001f, 1021.880000f));
  vertices->push_back(osg::Vec3(489291.083001f, -209156.143999f, 1021.880000f));
  vertices->push_back(osg::Vec3(489116.739999f, -209137.704001f, 1020.910000f));
  vertices->push_back(osg::Vec3(489116.740001f, -209137.703999f, 1020.910000f));
  vertices->push_back(osg::Vec3(489193.852999f, -209118.426001f, 1023.800000f));
  vertices->push_back(osg::Vec3(489193.853001f, -209118.425999f, 1023.800000f));
  vertices->push_back(osg::Vec3(489044.654999f, -209149.439001f, 1022.360000f));
  vertices->push_back(osg::Vec3(489044.655001f, -209149.438999f, 1022.360000f));
  vertices->push_back(osg::Vec3(489196.367999f, -209067.296001f, 1022.840000f));
  vertices->push_back(osg::Vec3(489196.368001f, -209067.295999f, 1022.840000f));
  vertices->push_back(osg::Vec3(489136.017999f, -209062.267001f, 1023.320000f));
  vertices->push_back(osg::Vec3(489136.018001f, -209062.266999f, 1023.320000f));
  vertices->push_back(osg::Vec3(489281.862999f, -208235.812001f, 1020.430000f));
  vertices->push_back(osg::Vec3(489281.863001f, -208235.811999f, 1020.430000f));
  vertices->push_back(osg::Vec3(488372.426999f, -206028.856001f, 1021.400000f));
  vertices->push_back(osg::Vec3(488372.427001f, -206028.855999f, 1021.400000f));
  vertices->push_back(osg::Vec3(485313.869999f, -206376.705001f, 1019.470000f));
  vertices->push_back(osg::Vec3(485313.870001f, -206376.704999f, 1019.470000f));
  vertices->push_back(osg::Vec3(484617.333999f, -205621.496001f, 1016.110000f));
  vertices->push_back(osg::Vec3(484617.334001f, -205621.495999f, 1016.110000f));
  vertices->push_back(osg::Vec3(482538.621999f, -202597.305001f, 999.770000f));
  vertices->push_back(osg::Vec3(482538.622001f, -202597.304999f, 999.770000f));
  vertices->push_back(osg::Vec3(480255.390999f, -202968.624001f, 986.310000f));
  vertices->push_back(osg::Vec3(480255.391001f, -202968.623999f, 986.310000f));
  vertices->push_back(osg::Vec3(477036.740999f, -201257.877001f, 972.850000f));
  vertices->push_back(osg::Vec3(477036.741001f, -201257.876999f, 972.850000f));
  vertices->push_back(osg::Vec3(473516.340999f, -200985.465001f, 960.830000f));
  vertices->push_back(osg::Vec3(473516.341001f, -200985.464999f, 960.830000f));
  vertices->push_back(osg::Vec3(472486.204999f, -198482.629001f, 958.430000f));
  vertices->push_back(osg::Vec3(472486.205001f, -198482.628999f, 958.430000f));
  vertices->push_back(osg::Vec3(471325.311999f, -194937.084001f, 940.640000f));
  vertices->push_back(osg::Vec3(471325.312001f, -194937.083999f, 940.640000f));
  vertices->push_back(osg::Vec3(469189.602999f, -194602.646001f, 927.190000f));
  vertices->push_back(osg::Vec3(469189.603001f, -194602.645999f, 927.190000f));
  vertices->push_back(osg::Vec3(466048.065999f, -195088.796001f, 907.000000f));
  vertices->push_back(osg::Vec3(466048.066001f, -195088.795999f, 907.000000f));
  vertices->push_back(osg::Vec3(463299.639999f, -196344.405001f, 885.850000f));
  vertices->push_back(osg::Vec3(463299.640001f, -196344.404999f, 885.850000f));
  vertices->push_back(osg::Vec3(459732.301999f, -196750.928001f, 866.140000f));
  vertices->push_back(osg::Vec3(459732.302001f, -196750.927999f, 866.140000f));
  vertices->push_back(osg::Vec3(459252.856999f, -196407.270001f, 865.180000f));
  vertices->push_back(osg::Vec3(459252.857001f, -196407.269999f, 865.180000f));
  vertices->push_back(osg::Vec3(435992.236999f, -197165.832001f, 769.530000f));
  vertices->push_back(osg::Vec3(435992.237001f, -197165.831999f, 769.530000f));
  vertices->push_back(osg::Vec3(433164.182999f, -195207.819001f, 756.070000f));
  vertices->push_back(osg::Vec3(433164.183001f, -195207.818999f, 756.070000f));
  vertices->push_back(osg::Vec3(423053.092999f, -191047.881001f, 702.720000f));
  vertices->push_back(osg::Vec3(423053.093001f, -191047.880999f, 702.720000f));
  vertices->push_back(osg::Vec3(414203.479999f, -189011.917001f, 673.400000f));
  vertices->push_back(osg::Vec3(414203.480001f, -189011.916999f, 673.400000f));
  vertices->push_back(osg::Vec3(401130.225999f, -191230.606001f, 645.520000f));
  vertices->push_back(osg::Vec3(401130.226001f, -191230.605999f, 645.520000f));
  vertices->push_back(osg::Vec3(394487.566999f, -188235.752001f, 628.220000f));
  vertices->push_back(osg::Vec3(394487.567001f, -188235.751999f, 628.220000f));
  vertices->push_back(osg::Vec3(387754.383999f, -185963.418001f, 612.350000f));
  vertices->push_back(osg::Vec3(387754.384001f, -185963.417999f, 612.350000f));
  vertices->push_back(osg::Vec3(382731.109999f, -184531.789001f, 604.180000f));
  vertices->push_back(osg::Vec3(382731.110001f, -184531.788999f, 604.180000f));
  vertices->push_back(osg::Vec3(379341.467999f, -184217.468001f, 609.950000f));
  vertices->push_back(osg::Vec3(379341.468001f, -184217.467999f, 609.950000f));
  vertices->push_back(osg::Vec3(380165.408999f, -185819.250001f, 609.950000f));
  vertices->push_back(osg::Vec3(380165.409001f, -185819.249999f, 609.950000f));
  vertices->push_back(osg::Vec3(379968.434999f, -185616.408001f, 609.950000f));
  vertices->push_back(osg::Vec3(379968.435001f, -185616.407999f, 609.950000f));
  vertices->push_back(osg::Vec3(380240.007999f, -185728.725001f, 610.910000f));
  vertices->push_back(osg::Vec3(380240.008001f, -185728.724999f, 610.910000f));
  vertices->push_back(osg::Vec3(380043.871999f, -185901.392001f, 610.430000f));
  vertices->push_back(osg::Vec3(380043.872001f, -185901.391999f, 610.430000f));
  vertices->push_back(osg::Vec3(380436.144999f, -186183.024001f, 609.470000f));
  vertices->push_back(osg::Vec3(380436.145001f, -186183.023999f, 609.470000f));
  vertices->push_back(osg::Vec3(380960.851999f, -179030.746001f, 613.320000f));
  vertices->push_back(osg::Vec3(380960.852001f, -179030.745999f, 613.320000f));
  vertices->push_back(osg::Vec3(379287.823999f, -176071.934001f, 600.820000f));
  vertices->push_back(osg::Vec3(379287.824001f, -176071.933999f, 600.820000f));
  vertices->push_back(osg::Vec3(369238.759999f, -181945.134001f, 578.230000f));
  vertices->push_back(osg::Vec3(369238.760001f, -181945.133999f, 578.230000f));
  vertices->push_back(osg::Vec3(357069.912999f, -183789.153001f, 580.630000f));
  vertices->push_back(osg::Vec3(357069.913001f, -183789.152999f, 580.630000f));
  vertices->push_back(osg::Vec3(347837.246999f, -180760.771001f, 573.420000f));
  vertices->push_back(osg::Vec3(347837.247001f, -180760.770999f, 573.420000f));
  vertices->push_back(osg::Vec3(344060.360999f, -171890.203001f, 554.680000f));
  vertices->push_back(osg::Vec3(344060.361001f, -171890.202999f, 554.680000f));
  vertices->push_back(osg::Vec3(342117.435999f, -171621.144001f, 548.910000f));
  vertices->push_back(osg::Vec3(342117.436001f, -171621.143999f, 548.910000f));
  vertices->push_back(osg::Vec3(342244.002999f, -169881.899001f, 549.390000f));
  vertices->push_back(osg::Vec3(342244.003001f, -169881.898999f, 549.390000f));
  vertices->push_back(osg::Vec3(339622.981999f, -168348.011001f, 538.810000f));
  vertices->push_back(osg::Vec3(339622.982001f, -168348.010999f, 538.810000f));
  vertices->push_back(osg::Vec3(339975.021999f, -164996.926001f, 541.700000f));
  vertices->push_back(osg::Vec3(339975.022001f, -164996.925999f, 541.700000f));
  vertices->push_back(osg::Vec3(335696.897999f, -155584.049001f, 543.140000f));
  vertices->push_back(osg::Vec3(335696.898001f, -155584.048999f, 543.140000f));
  vertices->push_back(osg::Vec3(326091.236999f, -150158.443001f, 540.260000f));
  vertices->push_back(osg::Vec3(326091.237001f, -150158.442999f, 540.260000f));
  vertices->push_back(osg::Vec3(319226.458999f, -139922.462001f, 527.280000f));
  vertices->push_back(osg::Vec3(319226.459001f, -139922.461999f, 527.280000f));
  vertices->push_back(osg::Vec3(304762.646999f, -135871.489001f, 520.550000f));
  vertices->push_back(osg::Vec3(304762.647001f, -135871.488999f, 520.550000f));
  vertices->push_back(osg::Vec3(301134.120999f, -135419.704001f, 516.700000f));
  vertices->push_back(osg::Vec3(301134.121001f, -135419.703999f, 516.700000f));
  vertices->push_back(osg::Vec3(298483.762999f, -134035.014001f, 516.700000f));
  vertices->push_back(osg::Vec3(298483.763001f, -134035.013999f, 516.700000f));
  vertices->push_back(osg::Vec3(295316.241999f, -127481.204001f, 517.660000f));
  vertices->push_back(osg::Vec3(295316.242001f, -127481.203999f, 517.660000f));
  vertices->push_back(osg::Vec3(296506.471999f, -124764.629001f, 508.050000f));
  vertices->push_back(osg::Vec3(296506.472001f, -124764.628999f, 508.050000f));
  vertices->push_back(osg::Vec3(298176.984999f, -119458.046001f, 480.650000f));
  vertices->push_back(osg::Vec3(298176.985001f, -119458.045999f, 480.650000f));
  vertices->push_back(osg::Vec3(292588.769999f, -115039.107001f, 449.890000f));
  vertices->push_back(osg::Vec3(292588.770001f, -115039.106999f, 449.890000f));
  vertices->push_back(osg::Vec3(282390.508999f, -110071.991001f, 429.220000f));
  vertices->push_back(osg::Vec3(282390.509001f, -110071.990999f, 429.220000f));
  vertices->push_back(osg::Vec3(272562.726999f, -105460.268001f, 403.750000f));
  vertices->push_back(osg::Vec3(272562.727001f, -105460.267999f, 403.750000f));
  vertices->push_back(osg::Vec3(264532.025999f, -98428.689001f, 414.800000f));
  vertices->push_back(osg::Vec3(264532.026001f, -98428.688999f, 414.800000f));
  vertices->push_back(osg::Vec3(260486.080999f, -97266.119001f, 419.130000f));
  vertices->push_back(osg::Vec3(260486.081001f, -97266.118999f, 419.130000f));
  vertices->push_back(osg::Vec3(261134.001999f, -97324.792001f, 418.170000f));
  vertices->push_back(osg::Vec3(261134.002001f, -97324.791999f, 418.170000f));
  vertices->push_back(osg::Vec3(254125.892999f, -91739.092001f, 411.920000f));
  vertices->push_back(osg::Vec3(254125.893001f, -91739.091999f, 411.920000f));
  vertices->push_back(osg::Vec3(239818.822999f, -84942.207001f, 393.650000f));
  vertices->push_back(osg::Vec3(239818.823001f, -84942.206999f, 393.650000f));
  vertices->push_back(osg::Vec3(224446.411999f, -78948.308001f, 385.480000f));
  vertices->push_back(osg::Vec3(224446.412001f, -78948.307999f, 385.480000f));
  vertices->push_back(osg::Vec3(207414.384999f, -78644.045001f, 386.440000f));
  vertices->push_back(osg::Vec3(207414.385001f, -78644.044999f, 386.440000f));
  vertices->push_back(osg::Vec3(199957.005999f, -79551.805001f, 384.520000f));
  vertices->push_back(osg::Vec3(199957.006001f, -79551.804999f, 384.520000f));
  vertices->push_back(osg::Vec3(184758.938999f, -75534.359001f, 384.520000f));
  vertices->push_back(osg::Vec3(184758.939001f, -75534.358999f, 384.520000f));
  vertices->push_back(osg::Vec3(180635.880999f, -65165.944001f, 375.390000f));
  vertices->push_back(osg::Vec3(180635.881001f, -65165.943999f, 375.390000f));
  vertices->push_back(osg::Vec3(179258.733999f, -57511.590001f, 368.180000f));
  vertices->push_back(osg::Vec3(179258.734001f, -57511.589999f, 368.180000f));
  vertices->push_back(osg::Vec3(176247.953999f, -46304.986001f, 369.620000f));
  vertices->push_back(osg::Vec3(176247.954001f, -46304.985999f, 369.620000f));
  vertices->push_back(osg::Vec3(171401.537999f, -35911.426001f, 365.780000f));
  vertices->push_back(osg::Vec3(171401.538001f, -35911.425999f, 365.780000f));
  vertices->push_back(osg::Vec3(167835.875999f, -30822.773001f, 362.410000f));
  vertices->push_back(osg::Vec3(167835.876001f, -30822.772999f, 362.410000f));
  vertices->push_back(osg::Vec3(149963.981999f, -24636.090001f, 358.570000f));
  vertices->push_back(osg::Vec3(149963.982001f, -24636.089999f, 358.570000f));
  vertices->push_back(osg::Vec3(136963.650999f, -22665.504001f, 335.500000f));
  vertices->push_back(osg::Vec3(136963.651001f, -22665.503999f, 335.500000f));
  vertices->push_back(osg::Vec3(118379.294999f, -20294.264001f, 304.730000f));
  vertices->push_back(osg::Vec3(118379.295001f, -20294.263999f, 304.730000f));
  vertices->push_back(osg::Vec3(111409.741999f, -18893.648001f, 294.640000f));
  vertices->push_back(osg::Vec3(111409.742001f, -18893.647999f, 294.640000f));
  vertices->push_back(osg::Vec3(109838.973999f, -16690.884001f, 292.240000f));
  vertices->push_back(osg::Vec3(109838.974001f, -16690.883999f, 292.240000f));
  vertices->push_back(osg::Vec3(110627.710999f, -10651.723001f, 278.300000f));
  vertices->push_back(osg::Vec3(110627.711001f, -10651.722999f, 278.300000f));
  vertices->push_back(osg::Vec3(99983.531999f, -19856.729001f, 261.470000f));
  vertices->push_back(osg::Vec3(99983.532001f, -19856.728999f, 261.470000f));
  vertices->push_back(osg::Vec3(87043.549999f, -21562.446001f, 232.150000f));
  vertices->push_back(osg::Vec3(87043.550001f, -21562.445999f, 232.150000f));
  vertices->push_back(osg::Vec3(73210.056999f, -19444.339001f, 200.910000f));
  vertices->push_back(osg::Vec3(73210.057001f, -19444.338999f, 200.910000f));
  vertices->push_back(osg::Vec3(66890.939999f, -14871.173001f, 175.920000f));
  vertices->push_back(osg::Vec3(66890.940001f, -14871.172999f, 175.920000f));
  vertices->push_back(osg::Vec3(73260.347999f, -5710.591001f, 152.840000f));
  vertices->push_back(osg::Vec3(73260.348001f, -5710.590999f, 152.840000f));
  vertices->push_back(osg::Vec3(71572.232999f, 1353.676999f, 128.330000f));
  vertices->push_back(osg::Vec3(71572.233001f, 1353.677001f, 128.330000f));
  vertices->push_back(osg::Vec3(55551.900999f, 1388.880999f, 103.820000f));
  vertices->push_back(osg::Vec3(55551.901001f, 1388.881001f, 103.820000f));
  vertices->push_back(osg::Vec3(39826.612999f, 1115.630999f, 82.190000f));
  vertices->push_back(osg::Vec3(39826.613001f, 1115.631001f, 82.190000f));
  vertices->push_back(osg::Vec3(23398.920999f, 2286.582999f, 67.290000f));
  vertices->push_back(osg::Vec3(23398.921001f, 2286.583001f, 67.290000f));
  vertices->push_back(osg::Vec3(5361.064999f, 1419.055999f, 53.830000f));
  vertices->push_back(osg::Vec3(5361.065001f, 1419.056001f, 53.830000f));
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

  for (int i = 0 ; i < vertices->size(); i += 2) {
    if (i + 4 >= vertices->size())
      break;
    polygon->addPrimitiveSet(new osg::DrawArrays(GL_POLYGON,  i, 4));
    border->addPrimitiveSet(new osg::DrawArrays(GL_LINE_LOOP, i, 4));
  }
  border->getOrCreateStateSet()->setAttribute(new osg::LineWidth(5.0f));

  // creates a bounding box around the trace
  double minx = 0, miny = 0, minz = 0, maxx = 0, maxy = 0, maxz = 0;
  for (int i = 0 ; i < vertices->size(); ++i) {
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
  boxborder->setColorArray(colors.get());
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
