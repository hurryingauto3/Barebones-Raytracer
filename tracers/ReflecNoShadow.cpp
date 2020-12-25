#include "ReflecNoShadow.hpp"

ReflecNoShadow::ReflecNoShadow(World& w, int depth)
{
    this->w = &w;
    this->depth = depth;
}

ShadeInfo ReflecNoShadow::hit_objects(const Ray &ray) const
{
    ShadeInfo s = w->hit_objects(ray);
    s.depth = this->depth;
    return s;
}


ShadeInfo ReflecNoShadow::hit_objects(const Ray &ray, int depth) const
{
    ShadeInfo s = w->hit_objects(ray);
    s.depth = depth;
    return s;
}


RGBColor ReflecNoShadow::shade(const ShadeInfo& sinfo) const
{
    RGBColor diffuseColorSum(0);
    if(sinfo.depth == 0 || sinfo.material_ptr->lookAheadPhong())
    {
        RGBColor localColorSum(0);
        RGBColor localColor(0);
        for (const auto &lightSrc: w->lights)
        {
            localColor = sinfo.material_ptr->shade(sinfo, lightSrc);
            localColorSum += localColor;
        }
        diffuseColorSum = localColorSum;
    }

    if(sinfo.depth == 0)
    {
        RGBColor localCol = sinfo.material_ptr->applyMaxDepthColor(diffuseColorSum, sinfo);
        return localCol;
    }
    else
    {
        RGBColor localSecondSum(0);
        std::vector<Ray> rays = sinfo.material_ptr->getEmergingRays(sinfo);
        for(const auto &rayy: rays)
        {
            ShadeInfo sinf = this->hit_objects(rayy, sinfo.depth - 1);
            if(sinf.hit)
            {
                localSecondSum += this->shade(sinf) * rayy.w;
            }
            else
            {
                localSecondSum += this->w->bg_color * rayy.w;
            }
        }
        return sinfo.material_ptr->applyColour(diffuseColorSum + localSecondSum);
    }
}
