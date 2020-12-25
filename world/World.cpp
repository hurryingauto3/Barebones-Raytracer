#include "World.hpp"

#include <iostream>
World::World()
{
    this->vplane = ViewPlane();
    this->bg_color = RGBColor();
    this->camera_ptr = nullptr;
    this->sampler_ptr = nullptr;
    this->acceleration_ptr = nullptr;
}


World::~World()
{
    for (unsigned int i = 0; i < geometry.size(); i++)
    {
        delete geometry[i];
    }

    for (unsigned int i = 0; i < lights.size(); i++)
    {
        delete lights[i];
    }

    delete camera_ptr;
    delete sampler_ptr;
    delete acceleration_ptr;
    delete tracer;
}


void World::add_geometry(Geometry *geom_ptr)
{
    this->geometry.push_back(geom_ptr);
}


void World::set_camera(Camera *c_ptr)
{
    this->camera_ptr = c_ptr;
}


ShadeInfo World::hit_objects(const Ray &ray)
{
//    if (acceleration_ptr != NULL){
//        ShadeInfo s = acceleration_ptr->hit(ray);
////        std::cout << s.hit<<std::endl;
//        return s;
//    }

    ShadeInfo s(*this);
    Material * mPtr = 0;
    float t;
//    int index;
    float tmin = kHugeValue;
    Vector3D normal;
    Point3D local_hit;
    for (unsigned int i = 0; i < geometry.size(); i++){
        if (geometry[i]->hit(ray, t, s) && (t < tmin)){
//              sFinal = s;
//            std::cout << geometry[i]->material_ptr << " ";
            s.hit = true;
            tmin = t;
            mPtr = geometry[i]->get_material();
            normal = s.normal;
            local_hit = s.hit_point;
//            index = i;
        }
    }
    if (s.hit){
        s.t = tmin;
        s.normal = normal;
        s.hit_point = local_hit;
        s.material_ptr = mPtr;
    }

//    std::cout << index << " " << s.material_ptr << std::endl;

    return s;
}

void World::set_acceleration(Acceleration* a_ptr){
    this->acceleration_ptr = a_ptr;
}

void World::add_light(Light * light_ptr)
{
    this->lights.push_back(light_ptr);
}
