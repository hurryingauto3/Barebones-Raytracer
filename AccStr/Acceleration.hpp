#pragma once

class World;
class Ray; 
class ShadeInfo;


class Acceleration {
    
    protected:
        World* world;
    public:
    
        Acceleration() = default;
        virtual ShadeInfo hit (const Ray &ray) = 0;
        virtual ~Acceleration() = default;
};