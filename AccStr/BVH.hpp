#include "Acceleration.hpp"
#include "../utilities/BBox.hpp"
#include "../geometry/Geometry.hpp"
#include "../utilities/ShadeInfo.hpp"
#include "../world/World.hpp"
#include <vector>

class World;

struct Node {
    BBox bbox;
    int start, num_primitives, offset;

};

struct EnterNode {
    int parent, left, right;
};

struct TraverseNode {
    int i;
    float minT;
    TraverseNode(){};
    TraverseNode(int _i, float _minT) {
        this->i = _i;
        this->minT = _minT;
    }
};

class BVH: public Acceleration {
    public:

    std::vector<Geometry*> geometry;
    Node* bvhTree;
    int node_num, leaf_num;

    BVH() = default;
    BVH(World* world);

    virtual ~BVH();

    void build();
    virtual ShadeInfo hit(const Ray &ray) override;
};
