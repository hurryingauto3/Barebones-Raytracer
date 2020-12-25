
// #pragma once

// /**

// */

// #include "Geometry.hpp"
// #include "Triangle.hpp"
// #include <string>
// #include <iostream>
// #include <fstream>
// #include <sstream>

// #include "../utilities/Point3D.hpp"

// class Mesh : public Geometry {

// protected:
//   std::string file;

//   std::vector<Triangle*> triangles;// the vertices. they must not be colinear.

// public:
//   // Constructors. Passed vertices are assumed to be ordered for orientation,
//   Mesh(std::string file); // triangle with vertices at origin.

//   virtual ~Mesh() = default;

//   bool read_obj();

//   virtual std::string to_string() const;

//   // Get bounding box.
//   Material *get_material() const;
//   void set_material(Material *mPtr);

//   // Ray intersection. Set t and sinfo as per intersection with this object.
//   virtual bool hit(const Ray &ray, float &t, ShadeInfo &sinfo) const;

//   // Get bounding box.
//   virtual BBox getBBox() const;
//   virtual Point3D getCentroid() const;
//   void populateInGeom(World* w);

// };
