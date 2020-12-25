#include "Cosine.hpp"
#include <cmath>
#include <stdlib.h>

Cosine::Cosine()
{
    this->color = RGBColor();
    this->diffusivity = 1.0;
}

Cosine::Cosine(float c){
    this->color = RGBColor(c);
    this->diffusivity = 1.0;
}

Cosine::Cosine(float r, float g, float b)
{
    this->color = RGBColor(r, g, b);
    this->diffusivity = 1.0;
}

Cosine::Cosine(const RGBColor &c){
    this->color = c;
    this->diffusivity = 1.0;
}

Cosine::Cosine(const Cosine &other){
    this->color = other.color;
    this->diffusivity = other.diffusivity;
}

Cosine& Cosine::operator=(const Cosine &other){
    this->color = other.color;
    this->diffusivity = other.diffusivity;
    return *this;
}

/* Returned shade is: color * cos \theta.
 \theta is the angle between the normal at the hit pont and the ray.
 Assuming unit vectors, cos \theta = dot product of normal and -ray.dir.
*/

RGBColor Cosine::applyMaxDepthColor(const RGBColor &arrivingLight, const ShadeInfo &sinfo)const
{
    return this->applyColour(arrivingLight);
}

RGBColor Cosine::shadeDiffuse(const ShadeInfo &sinfo, const Light * lightSrc)const{
    Vector3D a = -lightSrc->get_direction(sinfo.hit_point);
    a.normalize();
    Vector3D b = sinfo.normal;
    b.normalize();
    double dot = a * b;
    return std::max(dot, 0.0) * lightSrc->get_color(sinfo.hit_point) * this->diffusivity;
}


RGBColor Cosine::shadeSpecular(const ShadeInfo &sinfo, const Light * lightSrc) const{
    Vector3D l = -lightSrc->get_direction(sinfo.hit_point);
    Vector3D v = -sinfo.ray.d;
    l.normalize();
    v.normalize();
    Vector3D hh = l + v;
    hh.normalize();
    Vector3D n = sinfo.normal;
    n.normalize();
    float specAng = std::max(hh * n, 0.0);
    float coeff = pow(specAng, this->shininess);
    return lightSrc->get_color(sinfo.hit_point) * coeff * this->specularCoeff;
}


RGBColor Cosine::shade(const ShadeInfo &sinfo, const Light * lightSrc) const{
    RGBColor col(0);
    if(specularCoeff > 0)
    {
        col += this->shadeSpecular(sinfo, lightSrc);
    }
    if(diffusivity > 0)
    {
        col += this->shadeDiffuse(sinfo, lightSrc);
    }
    return col;
}


std::vector<Ray> Cosine::getEmergingRays(const ShadeInfo &sinfo) const
{
    std::vector<Ray> rays;
    return rays;
}

RGBColor Cosine::applyColour(const RGBColor &arrivingLight) const{
    return this->color * arrivingLight;
}


//RGBColor Cosine::applyColour(const RGBColor &arrivingLight, const RGBColor &reflecLight) const{
//    return this->color * (arrivingLight * this->diffusivity + reflecLight * this->reflectivity);
//}


Cosine::Cosine(const RGBColor &c, float diffusivity, float specularCoeff, float shininess)
{
    this->color = c;
    this->specularCoeff = specularCoeff;
    this->shininess = shininess;
    this->diffusivity = diffusivity;
//    this->reflectivity = reflectivity;
}
