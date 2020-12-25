#include "GlossySpec.hpp"

#include "../utilities/RGBColor.hpp"
#include "../utilities/ShadeInfo.hpp"

// Constructors.

GlossySpec::GlossySpec(const RGBColor &c)
{
    this->color = c;
    this->diffusivity = 0.8;
    this->specularCoeff = 0.2;
    this->shininess = 4;
}

GlossySpec::GlossySpec(const RGBColor &c, float diffusivity, float specularCoeff, float shininess)
{
    this->color = c;
    this->diffusivity = diffusivity;
    this->specularCoeff = specularCoeff;
    this->shininess = shininess;
}


bool GlossySpec::lookAheadPhong()
{
    return true;
}

