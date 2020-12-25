#pragma once

#include "Light.hpp"
#include "../utilities/Vector3D.hpp"

class DirectionalLight : public Light {
protected:
  Vector3D dir; // direction of projection, stored as a unit vector.

public:
  // Constructors
  DirectionalLight(Vector3D dir, RGBColor color, float intensity);

  // Copy constructor and assignment operator.
  DirectionalLight(const DirectionalLight &directionalLight);
  DirectionalLight &operator=(const DirectionalLight &other);

  // Destructor
  virtual ~DirectionalLight() = default;

  // Get direction of projection for a point.
  virtual Vector3D get_direction(const Point3D &p) const;
  virtual RGBColor get_color(const Point3D &p) const;
};

