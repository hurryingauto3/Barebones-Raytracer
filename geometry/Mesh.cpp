// #include "Mesh.hpp"
// #include <string>
// #include <bits/stdc++.h>


// Mesh::Mesh(std::string file){

//     this->file = file;
// }


// bool Mesh::read_obj()
// {
//     std::ifstream source;
//                // build a read-Stream
//     source.open(file, std::ios_base::in);

//     std::vector<Point3D> vertices;

//     for(std::string line; std::getline(source, line); )   //read stream line by line
//     {
//         std::istringstream in(line);      //make a stream for the line itself

//         std::string type;
//         in >> type;                  //and read the first whitespace-separated token

//         if(type == "v")       //and check its value
//         {
//             float x, y, z;
//             in >> x >> y >> z;       //now read the whitespace-separated floats
//     //        cout << x << ' ' << y << ' ' << z << endl;

//             vertices.push_back(Point3D(x, y, z));
//         }

//         if(type == "f")
//         {
//             int v1, v2, v3;

//             in >> v1 >> v2 >> v3;

//             this->triangles.push_back( new Triangle( vertices.at(v1-1), vertices.at(v2-1), vertices.at(v3-1) ) );
//         }

//         return true;
//     }
//     return true;
// }

// void Mesh::populateInGeom(World* w)
// {
//     for(unsigned int i = 0; i < this->triangles.size(); i++)
//     {
//         w->add_geometry(triangles[i]);
//     }
// }

// Material* Mesh::get_material() const
// {
//     return this->material_ptr;
// }

// void Mesh::set_material(Material *mPtr)
// {
//     this->material_ptr = mPtr;
//     for(unsigned int i = 0; i < this->triangles.size(); i++)
//     {
//         this->triangles[i]->set_material(mPtr);
//     }
// }

// bool Mesh::hit(const Ray &ray, float &t, ShadeInfo &sinfo) const
// {
//     return false;
// }


// Point3D Mesh::getCentroid() const
// {
//     return Point3D(0);
// }

// BBox Mesh::getBBox() const
// {
//     return BBox();
// }

// std::string Mesh::to_string() const
// {

// }
