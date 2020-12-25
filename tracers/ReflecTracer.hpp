#pragma once
#include "Tracer.hpp"


class ReflecTracer : public Tracer {
protected:
    int depth;

public:
  // Constructors.
  ReflecTracer(World& w, int depth);

  // Desctructor.
  virtual ~ReflecTracer() = default;

  virtual ShadeInfo hit_objects(const Ray &ray) const override;

  virtual RGBColor shade(const ShadeInfo& sinfo) const override;

  ShadeInfo hit_objects(const Ray &ray, int depth) const;

};


