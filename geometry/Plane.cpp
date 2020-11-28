#include "Plane.hpp"
#include <string>

Plane::Plane(){
    this->a = Point3D(0, 0, 0);
    this->n = Vector3D(0, 1, 0);
}

Plane::Plane(const Point3D &pt, const Vector3D &n)
{
    this->a = pt;
    this->n = n;
    this->n.normalize();
}

Plane::Plane(const Plane &object){
    this->a = object.a;
    this->n = object.n;
}

Plane& Plane::operator=(const Plane &rhs){
    this->a = rhs.a;
    this->n = rhs.n;
    return *this;
}

std::string Plane::to_string() const{
//    return std::string("A: ") + std::to_string(this->a) + std::string(" N: ") + std::to_string(this->n) + std::string("\n");
    return "print plane not implemented";
}

bool Plane::hit(const Ray &ray, float &t, ShadeInfo &s) const{
    
    double myT = (this->a - ray.o) * this->n / (ray.d * this->n);

    if(myT < kEpsilon)
    {
        return false;
    }

    t = myT;

    s.hit = true;
    s.material_ptr = this->material_ptr;
    s.normal = this->n;
    s.ray = ray;
    s.hit_point = ray.o + ray.d * myT;
    s.t = myT;
    return true;
}

BBox Plane::getBBox()const{
    return BBox();
}
