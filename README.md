About
======

This project is currently a mix / braindump of several things

* First, a GPX parser which tends to extract lat, long and elevation of each
  containing coordinates. It makes use of GDAL/OGR2.

* Second, an attempt to use the previous parser to generate an array of vertices
  usable in a 3D scene, using OpenSceneGraph.

It is clearly in a draft-state now.

Compile the parser
===================

```
make
```

Use the parser
===============

```
./parser rando.gpx
```

Compile osc-render.cpp
=======================


```
g++ osg-renderer.cpp $(pkg-config openscenegraph --libs) $(pkg-config openthreads --libs)
./a.out
```

What kind of horror does it produce ?
=========================================

![](https://raw.githubusercontent.com/pmauduit/3d-gpx-reader/master/rando.png)
