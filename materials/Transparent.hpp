#pragma once

#include "Material.hpp"

#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"

class Transparent : public Material {
protected:
    float refInd;
    RGBColor color;

public:
  // Constructors.
  Transparent(RGBColor c, float refInd);

  // Desctructor.
  virtual ~Transparent() = default;

  /* Returned shade is: color * cos \theta.
     \theta is the angle between the normal at the hit pont and the ray.
     Assuming unit vectors, cos \theta = dot product of normal and -ray.dir.
  */
  virtual RGBColor shade(const ShadeInfo &sinfo, const Light* lightSrc) const override;
  virtual RGBColor applyColour(const RGBColor &arrivingLight) const override;
  virtual RGBColor applyMaxDepthColor(const RGBColor &arrivingLight, const ShadeInfo &sinfo)const override;

  virtual std::vector<Ray> getEmergingRays(const ShadeInfo &sinfo) const override;

  virtual bool lookAheadPhong();

};
