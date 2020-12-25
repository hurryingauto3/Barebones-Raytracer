#include "SpotLight.hpp"
#include "../utilities/Point3D.hpp"
#include <cmath>

SpotLight::SpotLight(Point3D pos, RGBColor color, float intensity, Vector3D dir, float attenuation, float theta)
{
    this->pos = pos;
    this->color = color;
    this->intensity = intensity;
    this->dir = dir;
    this->attenuation = attenuation;
    this->theta = theta;
}

SpotLight::SpotLight(const SpotLight &other)
{
    this->pos = other.pos;
    this->color = other.color;
    this->intensity = other.intensity;
    this->dir = other.dir;
    this->attenuation = other.attenuation;
    this->theta = other.theta;
}

SpotLight& SpotLight::operator=(const SpotLight &other)
{
    this->pos = other.pos;
    this->color = other.color;
    this->intensity = other.intensity;
    this->dir = other.dir;
    this->attenuation = other.attenuation;
    this->theta = other.theta;
    return *this;
}

Vector3D SpotLight::get_direction(const Point3D &p) const
{
    return p - this->pos;
}

RGBColor SpotLight::get_color(const Point3D &p) const
{
    float angle;
    Vector3D dr = this->dir;
    dr.normalize();
    Vector3D toP = p - this->pos;
    toP.normalize();
    float cosAngle = toP * dr;
    angle = acos(cosAngle);
    if(angle >= -this->theta && angle <= this->theta)
    {
        return this->color * this->intensity * pow(cosAngle, this->attenuation);
    }
    return RGBColor(0);
}


