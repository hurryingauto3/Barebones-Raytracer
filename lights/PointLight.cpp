#include "PointLight.hpp"
#include "../utilities/Point3D.hpp"

PointLight::PointLight(Point3D pos, RGBColor color, float intensity)
{
    this->color = color;
    this->pos = pos;
    this->intensity = intensity;
}

PointLight::PointLight(const PointLight &pointLight)
{
    this->color = pointLight.color;
    this->pos = pointLight.pos;
    this->intensity = pointLight.intensity;
}

PointLight& PointLight::operator=(const PointLight &other)
{
    this->color = other.color;
    this->pos = other.pos;
    this->intensity = other.intensity;
    return *this;
}

Vector3D PointLight::get_direction(const Point3D &p) const
{
    return p - this->pos;
}

RGBColor PointLight::get_color(const Point3D &p) const
{
    return this->color * this->intensity;
}


