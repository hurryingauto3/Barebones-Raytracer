#pragma once
#include "Tracer.hpp"


class BasicTracer : public Tracer {
public:
  // Constructors.
  BasicTracer(World& w);

  // Desctructor.
  virtual ~BasicTracer() = default;

  virtual ShadeInfo hit_objects(const Ray &ray) const override;

  virtual RGBColor shade(const ShadeInfo& sinfo) const override;
};


