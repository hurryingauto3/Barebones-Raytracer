#include "Triangle.hpp"

Triangle::Triangle(){
    this->v0 = Point3D();
    this->v1 = Point3D();
    this->v2 = Point3D();
}

Triangle::Triangle(const Point3D & v0, const Point3D & v1, const Point3D & v2){
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
}

Triangle::Triangle(const Triangle &object){
    this->v0 = object.v0;
    this->v1 = object.v1;
    this->v2 = object.v2;
}

Triangle& Triangle::operator=(const Triangle &rhs){
    this->v0 = rhs.v0;
    this->v1 = rhs.v1;
    this->v2 = rhs.v2;
    return *this;
}

std::string Triangle::to_string() const{
    return "triangle string not implemented";
}

bool Triangle::hit(const Ray &ray, float &t, ShadeInfo &s)const{

    Vector3D v_0 = this->v1 - this->v0;
    Vector3D v_1 = this->v2 - this->v0;
    Vector3D v_2 = v_0^v_1;

    double myT = (this->v0 - ray.o) * v_2 / (ray.d * v_2);

    if(myT < kEpsilon)
    {
        return false;
    }

    Point3D temp = ray.o + myT*ray.d;

    float c = v0.x - v2.x;
    float d = v1.x - v2.x;
    float e = temp.x - v2.x;
    float f = v0.y - v2.y;
    float g = v1.y - v2.y;
    float h = temp.y - v2.y;

    float beta = (e*f - h*c) / (d*f - g*c);
    float alpha = (e - beta * d) / c;

    if(0 <= alpha && alpha <= 1 && 0 <= beta && beta <= 1 && (alpha + beta) <= 1 && (alpha + beta) >= 0)
    {
        t = myT;
        s.hit_point = temp;
	    s.normal = v_2;
	    s.normal.normalize();
	    s.ray = ray;
	    s.t = t;
        s.hit = true;
        s.material_ptr = this->material_ptr;
	    return true;
    }
    else
    {
        return false;
    }

 }





BBox Triangle::getBBox()const{
    return BBox(min(v0, min(v1, v2)), max(v0, max(v1, v2)));
}
