#pragma once

#include "../utilities/ShadeInfo.hpp"

class World;
class RGBColor;
class ShadeInfo;
class Ray;

class Tracer {
protected:
  World* w;

public:
  // Constructors.
  Tracer() = default; // does nothing.

  // Desctructor.
  virtual ~Tracer() = default;

  virtual ShadeInfo hit_objects(const Ray &ray) const = 0;

  virtual RGBColor shade(const ShadeInfo& sinfo) const = 0;
};

