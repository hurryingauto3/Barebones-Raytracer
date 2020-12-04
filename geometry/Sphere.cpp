#include "Sphere.hpp"
#include <iostream>
#include <cmath>

Sphere::Sphere(){
    this->c = Point3D(0,0,0);
    this->r = 0;
}

Sphere::Sphere(const Point3D &center, float radius){
    this->c = center;
    this->r = radius;
}

Sphere::Sphere(const Sphere &object){
    this->c = object.c;
    this->r = object.r;
}

Sphere& Sphere::operator=(const Sphere &rhs){
    this->c = rhs.c;
    this->r = rhs.r;
    return *this;
}

std::string Sphere::to_string()const{
    return "print sphere not implemented";
}

bool Sphere::hit(const Ray &ray, float &t, ShadeInfo &s)const{
    double a = ray.d * ray.d;
    double b = ray.d * (ray.o - this->c) * 2;
    double c = (ray.o - this->c) * (ray.o - this->c) - this->r * this->r;
    double discrim = b * b - 4 * a * c;
    double t1 = (-b - sqrt(discrim)) / (2 * a);
    double t2 = (-b + sqrt(discrim)) / (2 * a);

    float myT;
    if(t1 < kEpsilon && t2 < kEpsilon)
    {
        return false;
    }
    else if(t1 >= kEpsilon && t2 >= kEpsilon)
    {
        myT = std::min(t1, t2);
    }
    else
    {
        myT = std::max(t1, t2);
    }

    t = myT;

    s.hit = true;
    s.material_ptr = this->material_ptr;
    s.ray = ray;
    s.hit_point = ray.o + ray.d * myT;
    s.normal = s.hit_point - this->c;
    s.normal.normalize();
    s.t = myT;
    return true;
}

BBox Sphere::getBBox()const{
    Point3D mini = this->c - Vector3D(this->r);
    Point3D maxi = this->c + Vector3D(this->r);
    return BBox(mini, maxi);
}

