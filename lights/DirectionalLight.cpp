#include "DirectionalLight.hpp"
#include "../utilities/Vector3D.hpp"


// Constructors
DirectionalLight::DirectionalLight(Vector3D dir, RGBColor color, float intensity)
{
    this->dir = dir;
    this->color = color;
    this->intensity = intensity;
}

// Copy constructor and assignment operator.
DirectionalLight::DirectionalLight(const DirectionalLight &directionalLight)
{
    this->dir = directionalLight.dir;
    this->color = directionalLight.color;
    this->intensity = directionalLight.intensity;
}

DirectionalLight& DirectionalLight::operator=(const DirectionalLight &other)
{
    this->dir = other.dir;
    this->color = other.color;
    this->intensity = other.intensity;
    return *this;
}

Vector3D DirectionalLight::get_direction(const Point3D &p) const
{
    return this->dir;
}

RGBColor DirectionalLight::get_color(const Point3D &p) const
{
    return this->color * this->intensity;
}


