#include "Perspective.hpp"

Perspective::Perspective()
{
    this->pos = Point3D(0.0, 0.0, 0.0);  //Camera position set to origin
}


Perspective::Perspective(float c)
{
    this->pos = Point3D(c, c, c);  //Defining camera position
}


Perspective::Perspective(float x, float y, float z)
{
    this->pos = Point3D(x, y, z);  //Camera position set to (x,y,z)
}


Perspective::Perspective(const Point3D &pt)
{
    this->pos = pt;  // Assign the co-ordinates pt to the camera's position
}


Perspective::Perspective(const Perspective &camera)
{
    this->pos = camera.pos;  //Copy Constructor to copy "camera" into our object
}


Perspective& Perspective::operator=(const Perspective &other)
{
    // Operator overload for assignment of position from another object
    this->pos = other.pos;
    return *this;
}


Vector3D Perspective::get_direction(const Point3D &p) const
{
    //Calculating vector between point p and camera position
    Vector3D projVec = p - this->pos;
    return projVec;
}
