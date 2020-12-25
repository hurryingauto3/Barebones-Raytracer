#include "Transparent.hpp"
#include <cmath>

Transparent::Transparent(RGBColor c, float refInd)
{
    this->color = c;
    this->refInd = refInd;
}

RGBColor Transparent::shade(const ShadeInfo &sinfo, const Light* lightSrc) const
{
    return RGBColor(0);
}

RGBColor Transparent::applyColour(const RGBColor &arrivingLight) const
{
    return arrivingLight * this->color;
}

RGBColor Transparent::applyMaxDepthColor(const RGBColor &arrivingLight, const ShadeInfo &sinfo)const
{
    return sinfo.w->bg_color * this->color;
}

std::vector<Ray> Transparent::getEmergingRays(const ShadeInfo &sinfo) const
{
    float critAngle = asin(1 / this->refInd);
    Vector3D arriv = sinfo.ray.d;
    arriv.normalize();
    Vector3D norm = sinfo.normal;
    norm.normalize();
    std::vector<Ray> rays;

    if(norm * (-arriv) >= 0)
    {
        float c1 = norm * arriv;
        float c2 = sqrt(1 - pow(1 / this->refInd, 2) * (1 - pow(c1, 2)));
        float n = 1 / this->refInd;
        Vector3D T = n * arriv + (n * c1 - c2) * norm;
        T.normalize();
        Ray transmitRay(sinfo.hit_point, T);
        float costheta1 = norm * (-arriv);
        float costheta2 = (-norm) * T;
        float fr1 = pow((refInd * costheta1 - costheta2) / (refInd * costheta1 + costheta2) , 2.0);
        float fr2 = pow((costheta2 - refInd * costheta1) / (costheta2 + refInd * costheta1) , 2.0);
        float frr = (fr1 + fr2) / 2.0;
        float trr = 1 - frr;

        transmitRay.w = trr;
        rays.push_back(transmitRay);

        Vector3D incom = -sinfo.ray.d;
        incom.normalize();

        float projRatio = incom * norm;

        Vector3D projection = norm * projRatio;
        Vector3D ortho = projection - incom;
        Vector3D leaving = projection + ortho;

        Ray reflecRay(sinfo.hit_point, leaving);
        reflecRay.w = frr;
        rays.push_back(reflecRay);

        return rays;

    } else if(asin((-norm) * (-arriv)) > critAngle)
    {
        Vector3D incom = -sinfo.ray.d;
        incom.normalize();

        float projRatio = incom * (-norm);

        Vector3D projection = (-norm) * projRatio;
        Vector3D ortho = projection - incom;
        Vector3D leaving = projection + ortho;

        Ray reflecRay(sinfo.hit_point, leaving);
        reflecRay.w = 1.0;
        rays.push_back(reflecRay);

        return rays;
    } else {

    }
}

bool Transparent::lookAheadPhong()
{
    return false;
}
