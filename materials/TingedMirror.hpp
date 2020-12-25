#pragma once

#include "Cosine.hpp"

#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"

class TingedMirror : public Cosine {
protected:
    float reflectivity;
    float phongReflectivity;

public:
  // Constructors.
  TingedMirror(const RGBColor &c);
  TingedMirror(const RGBColor &c, float diffusivity, float specularCoeff, float shininess, float reflectivity);

  // Desctructor.
  virtual ~TingedMirror() = default;

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

