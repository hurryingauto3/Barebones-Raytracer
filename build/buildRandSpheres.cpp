///
////     This builds a scene that consists of 35 shaded spheres and a plane.
////     Perspective viewing is used with a single sample per pixel.
////     The spheres are the same as those in the Chapter 14 page one image.
//
////     Courtesy Kevin Suffern.
////  */
//
// #include "../cameras/Parallel.hpp"
// #include "../cameras/Perspective.hpp"
//
// #include "../geometry/Plane.hpp"
// #include "../geometry/Sphere.hpp"
//
// #include "../materials/GlossySpec.hpp"
// #include "../materials/TingedMirror.hpp"
// #include "../materials/Transparent.hpp"
// #include "../samplers/Simple.hpp"
//
// #include "../utilities/Constants.hpp"
// #include "../utilities/Vector3D.hpp"
//
// #include "../world/World.hpp"
//
// #include "../lights/PointLight.hpp"
//
// void
// World::build(void) {
//   // view plane
//   vplane.top_left.x = -50;
//   vplane.top_left.y = 50;
//   vplane.top_left.z = 150;
//   vplane.bottom_right.x = 50;
//   vplane.bottom_right.y = -50;
//   vplane.bottom_right.z = 150;
//   vplane.hres = 800;
//   vplane.vres = 800;
//
//   bg_color = black;  // background color.
//
//   // camera and sampler.
//   set_camera(new Perspective(0, 0, 200));
//   sampler_ptr = new Simple(camera_ptr, &vplane);
//
//   // colors
//   RGBColor yellow(1, 1, 0);  // yellow
//   RGBColor brown(0.71, 0.40, 0.16);  // brown
//   RGBColor darkGreen(0.0, 0.41, 0.41);  // darkGreen
//   RGBColor orange(1, 0.75, 0);  // orange
//   RGBColor green(0, 0.6, 0.3);  // green
//   RGBColor lightGreen(0.65, 1, 0.30);  // light green
//   RGBColor darkYellow(0.61, 0.61, 0);  // dark yellow
//   RGBColor lightPurple(0.65, 0.3, 1);  // light purple
//   RGBColor darkPurple(0.5, 0, 1);  // dark purple
//   RGBColor grey(0.25);  // grey
//   RGBColor white(1.0);
//
//   add_light(new PointLight(Point3D(50,3,84), white, 1));
//    add_light(new PointLight(Point3D(0,3,84), white, 1));
//    //   add_light(new PointLight(Point3D(5,3,84), white));
//
//
//
//    for (int i = 0; i < 100; i++){
//      float HI = 255;
//      float LO = 0;
//      float x = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
//      float y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
//      float z = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
//      RGBColor c(x,y,z);
//      Sphere* s = new Sphere(Point3D(x+50,y+50,z+50), 10);
//      s->set_material(new GlossySpec(c));
//      add_geometry(s);
//    }
////    for (int i = 0; i < 100; i++){
////      float HI = 100;
////      float LO = 0;
////      float x = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      float y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      float z = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      RGBColor c(x,y,z);
////      Sphere* s = new Sphere(Point3D(-x,-y,z), 12);
////      s->set_material(new TingedMirror(c));
////      add_geometry(s);
////    }
////
////    for (int i = 0; i < 100; i++){
////      float HI = 100;
////      float LO = 0;
////      float x = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      float y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      float z = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      RGBColor c(x,y,z);
////      Sphere* s = new Sphere(Point3D(-x,y,z), 12);
////      s->set_material(new TingedMirror(c));
////      add_geometry(s);
////    }
////    for (int i = 0; i < 100; i++){
////      float HI = 100;
////      float LO = 0;
////      float x = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      float y = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      float z = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
////      RGBColor c(x,y,z);
////      Sphere* s = new Sphere(Point3D(x,-y,z), 12);
////      s->set_material(new TingedMirror(c));
////      add_geometry(s);
////}
//  // vertical plane
//   Plane* plane_ptr = new Plane(Point3D(0, 0, -150), Vector3D(0, 0, 1));
//   plane_ptr->set_material(new GlossySpec(grey));
//   add_geometry(plane_ptr);
// }
