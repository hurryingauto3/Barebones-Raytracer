#include "TingedMirror.hpp"

#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"

TingedMirror::TingedMirror(const RGBColor &c)
{
    this->color = c;
    this->reflectivity = 1.0;
    this->phongReflectivity = 0.0;
}

TingedMirror::TingedMirror(const RGBColor &c, float diffusivity, float specularCoeff, float shininess, float reflectivity)
{
    this->color = c;
    this->reflectivity = reflectivity;
    this->phongReflectivity = 1 - reflectivity;
    this->diffusivity = diffusivity;
    this->shininess = shininess;
    this->specularCoeff = specularCoeff;
}

RGBColor TingedMirror::shade(const ShadeInfo &sinfo, const Light* lightSrc) const
{
    return RGBColor(0);
}

RGBColor TingedMirror::applyColour(const RGBColor &arrivingLight) const
{
    return this->color * arrivingLight;
}

RGBColor TingedMirror::applyMaxDepthColor(const RGBColor &arrivingLight, const ShadeInfo &sinfo)const
{
    return sinfo.w->bg_color * this->color;
}

std::vector<Ray> TingedMirror::getEmergingRays(const ShadeInfo &sinfo) const
{
    std::vector<Ray> rays;

    if(this->reflectivity == 0)
    {
        return rays;
    }

    Vector3D incom = -sinfo.ray.d;
    Vector3D norm = sinfo.normal;
    incom.normalize();
    norm.normalize();

    float projRatio = incom * norm;

    Vector3D projection = norm * projRatio;
    Vector3D ortho = projection - incom;
    Vector3D leaving = projection + ortho;

    Ray reflecRay(sinfo.hit_point, leaving);
    reflecRay.w = this->reflectivity;
    rays.push_back(reflecRay);

    return rays;
}

bool TingedMirror::lookAheadPhong()
{
    return this->phongReflectivity > 0.0;
}

