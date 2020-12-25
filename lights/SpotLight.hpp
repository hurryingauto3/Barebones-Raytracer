#pragma once

#include "Light.hpp"
#include "../utilities/Point3D.hpp"

class SpotLight : public Light {
protected:
  Point3D pos; // direction of projection, stored as a unit vector.
  Vector3D dir;
  float attenuation;
  float theta;

public:
  // Constructors
  SpotLight(Point3D pos, RGBColor color, float intensity, Vector3D dir, float attenuation, float theta);

  // Copy constructor and assignment operator.
  SpotLight(const SpotLight &other);
  SpotLight &operator=(const SpotLight &other);

  // Destructor
  virtual ~SpotLight() = default;

  // Get direction of projection for a point.
  virtual Vector3D get_direction(const Point3D &p) const;
  virtual RGBColor get_color(const Point3D &p) const;
};

