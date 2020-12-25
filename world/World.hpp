#pragma once

/**
   This file declares the World class which contains all the information about
   the scene - geometry and materials, lights, viewplane, camera, samplers, and
   acceleration structures.

   It also traces rays through the scene.

   Courtesy Kevin Suffern.
*/

#include <vector>

#include "../utilities/RGBColor.hpp"

#include "ViewPlane.hpp"
#include "../geometry/Geometry.hpp"
#include "../samplers/Sampler.hpp"
#include "../lights/Light.hpp"
#include "../AccStr/Acceleration.hpp"
#include "../tracers/Tracer.hpp"

class Camera;
class Geometry;
class Ray;
class Sampler;
class ShadeInfo;
class Light;
class Material;
class Acceleration;
class Tracer;

class World {
public:
  ViewPlane vplane;
  RGBColor bg_color;
  std::vector<Geometry *> geometry;
  std::vector<Light *> lights;
  Camera *camera_ptr;
  Sampler *sampler_ptr;
  Acceleration *acceleration_ptr;
  Tracer* tracer;

public:
  // Constructors.
  World(); // initialize members.

  // Destructor.
  ~World(); // free memory.

  // Add to the scene.
  void add_geometry(Geometry *geom_ptr);
  void add_light(Light * light_ptr);
  void set_camera(Camera *c_ptr);
  void set_acceleration(Acceleration* a_ptr);


  // Build scene - add all geometry, materials, lights, viewplane, camera,
  // samplers, and acceleration structures
  void build();

  // Returns appropriate shading information corresponding to intersection of
  // the ray with the scene geometry.
  ShadeInfo hit_objects(const Ray &ray);
};
