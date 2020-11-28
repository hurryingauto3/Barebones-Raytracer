#include "ViewPlane.hpp"


ViewPlane::ViewPlane()
{
    this->hres = 640;
    this->vres = 480;
    this->top_left = Point3D(-320, 240, 0);
    this->bottom_right = Point3D(top_left.x + hres, top_left.y + vres,0);
    this->normal = Vector3D(0, 0, -1);
}


int ViewPlane::get_hres() const
{
    return hres;
}


void ViewPlane::set_hres(int hresVal)
{
    this->hres = hresVal;
}


int ViewPlane::get_vres() const
{
    return vres;
}


void ViewPlane::set_vres(int vresVal)
{
    this->vres = vresVal;
}
