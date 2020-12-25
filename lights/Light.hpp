#pragma once
#include "../utilities/RGBColor.hpp"

class Point3D;
class Vector3D;

class Light {
protected:
  RGBColor color;
  float intensity;

public:
  // Constructors.
  Light() = default; // does nothing.

  // Copy constuctor and assignment operator.
  Light(const Light &light) = default;
  Light &operator=(const Light &other) = default;

  // Desctructor.
  virtual ~Light() = default;

  // Get direction of light for a point.
  virtual Vector3D get_direction(const Point3D &p) const = 0;

  // Get color cast by light at a point.
  virtual RGBColor get_color(const Point3D &p) const = 0;
};
