#pragma once
#include "Tracer.hpp"


class ReflecNoShadow : public Tracer {
protected:
    int depth;

public:
  // Constructors.
  ReflecNoShadow(World& w, int depth);

  // Desctructor.
  virtual ~ReflecNoShadow() = default;

  virtual ShadeInfo hit_objects(const Ray &ray) const override;

  virtual RGBColor shade(const ShadeInfo& sinfo) const override;

  ShadeInfo hit_objects(const Ray &ray, int depth) const;

};


