#include "Light.hpp"
#include "../utilities/ShadeInfo.hpp"

class Ambient: public Light{
    //Constructors
    Ambient(); //Sets color to 1,1,1
    Ambient(float c); //Sets color to c,c,c
    Ambient(float r, float g, float b); //Sets color to r,g,b
    Ambient(const RGBColor& c); //Sets color color to RGBColor object, c.
    //Destructors
    virtual ~Ambient() = default;

};
