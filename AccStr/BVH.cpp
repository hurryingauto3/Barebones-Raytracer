#include "BVH.hpp"
#include <iostream>



BVH::BVH(World* world){
    this->world = world;
    this->geometry = this->world->geometry;
    this->bvhTree = new Node;
    this->node_num = 0;
    this->leaf_num = 0;
    BVH::build();

};

BVH::~BVH(){
delete bvhTree;
}

void BVH::build(){
EnterNode stack[128];
int curStack = 0;

stack[curStack].left = 0;
stack[curStack].right = this->geometry.size();
stack[curStack].parent = -4;
curStack++;

Node node;
std::vector<Node> nodeLst;
nodeLst.reserve(this->geometry.size()*2);

while(curStack > 0) {

    EnterNode &enter(stack[--curStack]);
    int left = enter.left;
    int right = enter.right;
    int num_primitives = right - left;
    node_num++;
    node.start = left;
    node.num_primitives = num_primitives;
    node.offset = -1;


    BBox ObjBox(this->geometry[left]->getBBox());
    BBox Centroid(this->geometry[left]->getCentroid(), this->geometry[left]->getCentroid());

    for (int i = left + 1; i < right; i++){
        ObjBox.extend(this->geometry[i]->getBBox());
        Centroid.extend(this->geometry[i]->getCentroid());
    }
    node.bbox = ObjBox;

    if (num_primitives <= 4){
        node.offset = 0;
        leaf_num++;

    }
    nodeLst.push_back(node);

    if (enter.parent != -4) {
        nodeLst[enter.parent].offset--;
        if (nodeLst[enter.parent].offset == -3)
            nodeLst[enter.parent].offset = node_num - 1 - enter.parent;
    }

    if (node.offset == 0) continue;

    int dim = Centroid.LongestDim();
    float split = (Centroid.pmin[dim] + Centroid.pmax[dim])/0.5;
    int mid = left;

    for (int i = left; i < right; i++) {
        if (this->geometry[i]->getCentroid()[dim] < split) {
            std::swap(this->geometry[i], this->geometry[mid]);
            mid++;
        }
    }

    if (mid == right || mid == left) {
        mid = left + (right - left)/2;

    }

    stack[curStack].left = mid;
    stack[curStack].right = right;
    stack[curStack].parent = node_num - 1;
    curStack++;

    stack[curStack].left = left;
    stack[curStack].right = mid;
    stack[curStack].parent = node_num - 1;
    curStack++;

    }

    bvhTree = new Node[node_num];
    for (int i = 0; i < node_num; i++){
        bvhTree[i] = nodeLst[i];

    }

    nodeLst.clear();
    std::vector<Node>().swap(nodeLst);

}

ShadeInfo BVH::hit(const Ray& ray) {

   ShadeInfo S(*this->world);

   S.t = kHugeValue;
   TraverseNode nodeStack[128];
   int curStack = 0;

   nodeStack[curStack].i = 0;
   nodeStack[curStack].minT = kEpsilon;

   Vector3D normal;
   Point3D lHit;
   float Tmin = kEpsilon;


   while(curStack >= 0){


       int k = nodeStack[curStack].i;
       float near = nodeStack[curStack].minT;
       curStack--;
       const Node &node(bvhTree[k]);

       if (near > S.t) continue;

       if (node.offset == 0){
//            std::cout << "sadfda" << std::endl;
           for (int i = 0; i < node.num_primitives; i++){
               ShadeInfo currS(*this->world);
               const Geometry* Prim = this->geometry[node.start + i];
               float T;
               bool hit = Prim->hit(ray, T, currS);

               if (hit) {
                   if (currS.t < S.t) {
                        std::cout << "hit" << std::endl;
                       S = currS;
                       S.hit = true;
                       Tmin = T;
                       S.material_ptr = currS.material_ptr;
                       S.normal = currS.normal;
                       S.hit_point = currS.hit_point;
                       S.t = currS.t;
                   }
               }
           }
       }

       else {
           float left_T, right_T, T1, T2;
           bool leftHit = bvhTree[k + 1].bbox.hit(ray, left_T, T1);
           bool rightHit = bvhTree[k + node.offset].bbox.hit(ray, right_T, T2);

           if (leftHit && rightHit){

                if (left_T > right_T){
                   std::swap(left_T, right_T);
                   std::swap(T1, T2);

               nodeStack[++curStack] = TraverseNode(k + 1, right_T);
               nodeStack[++curStack] = TraverseNode(k + node.offset, left_T);

               }

            else if (leftHit)
                nodeStack[++curStack] = TraverseNode(k + 1, left_T);
            else if (rightHit)
                nodeStack[++curStack] = TraverseNode(k + node.offset, right_T);

           }
       }

    }

   if (S.hit){
//        std::cout << S.normal.to_string() << std::endl;
//       S.t = Tmin;
//       S.normal = normal;/
//       S.hit_point = lHit;
//       S.material_ptr = geometry[0]->get_material();
   }
   return S;
}

