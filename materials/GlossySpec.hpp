#pragma once

#include "Cosine.hpp"

#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"

class GlossySpec : public Cosine {

public:
  // Constructors.
  GlossySpec(const RGBColor &c);
  GlossySpec(const RGBColor &c, float diffusivity, float specularCoeff, float shininess);

  // Desctructor.
  virtual ~GlossySpec() = default;

  /* Returned shade is: color * cos \theta.
     \theta is the angle between the normal at the hit pont and the ray.
     Assuming unit vectors, cos \theta = dot product of normal and -ray.dir.
  */

  virtual bool lookAheadPhong();

};

