#pragma once
#include <vector>
#include "../utilities/Ray.hpp"

/**
   This file declares the Material class which is an abstract class for concrete
   materials to inherit from.

   Courtesy Kevin Suffern.
*/

class RGBColor;
class ShadeInfo;
class Light;

class Material {
protected:

public:
  // Constructors.
  Material() = default; // does nothing.

  // Copy constuctor and assignment operator.
  Material(const Material &other) = default;
  Material &operator=(const Material &other) = default;

  // Desctructor.
  virtual ~Material() = default;

  // Get color.
  virtual RGBColor shade(const ShadeInfo &sinfo, const Light* lightSrc) const = 0;
  virtual RGBColor applyColour(const RGBColor& leavingIntensity) const = 0;
  virtual RGBColor applyMaxDepthColor(const RGBColor &arrivingLight, const ShadeInfo &sinfo)const = 0;
  virtual std::vector<Ray> getEmergingRays(const ShadeInfo &sinfo) const = 0;
  virtual bool lookAheadPhong() = 0;

};
