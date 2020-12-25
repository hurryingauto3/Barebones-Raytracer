#include "BasicTracer.hpp"

BasicTracer::BasicTracer(World& w)
{
    this->w = &w;
}

ShadeInfo BasicTracer::hit_objects(const Ray &ray) const
{
    return w->hit_objects(ray);
}

RGBColor BasicTracer::shade(const ShadeInfo& sinfo) const
{
    RGBColor localColorSum(0);
    RGBColor localColor(0);
    for (const auto &lightSrc: w->lights)
    {
        localColor = sinfo.material_ptr->shade(sinfo, lightSrc);
        localColorSum += localColor;
    }
    return sinfo.material_ptr->applyColour(localColorSum);
}
