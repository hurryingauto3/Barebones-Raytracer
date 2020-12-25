#pragma once

#include "Light.hpp"
#include "../utilities/Point3D.hpp"

class PointLight : public Light {
protected:
  Point3D pos; // direction of projection, stored as a unit vector.

public:
  // Constructors
  PointLight(Point3D pos, RGBColor color, float intensity);

  // Copy constructor and assignment operator.
  PointLight(const PointLight &pointLight);
  PointLight &operator=(const PointLight &other);

  // Destructor
  virtual ~PointLight() = default;

  // Get direction of projection for a point.
  virtual Vector3D get_direction(const Point3D &p) const;
  virtual RGBColor get_color(const Point3D &p) const;
};
