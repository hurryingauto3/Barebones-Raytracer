////  Credit: Matthew Calligaro <matthewcalligaro@hotmail.com>
//
// #include "../cameras/Parallel.hpp"
// #include "../cameras/Perspective.hpp"
// #include "../geometry/Plane.hpp"
// #include "../geometry/Sphere.hpp"
// #include "../geometry/Triangle.hpp"
// #include "../materials/GlossySpec.hpp"
// #include "../samplers/Simple.hpp"
// #include "../utilities/Constants.hpp"
// #include "../world/World.hpp"
// #include "../lights/PointLight.hpp"
// #include "../lights/DirectionalLight.hpp"
// #include "../materials/Transparent.hpp"
// #include "../tracers/ReflecNoShadow.hpp"
//
// void World::build(void) {
//   // View plane
//   tracer = new ReflecNoShadow(*this, 20);
//   int n = 100;
//   vplane.top_left.x = -n;
//   vplane.top_left.y = n;
//   vplane.top_left.z = 80;
//   vplane.bottom_right.x = n;
//   vplane.bottom_right.y = -n;
//   vplane.bottom_right.z = 80;
//   vplane.hres = 1200;
//   vplane.vres = 1200;
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
//   RGBColor grey(0.3, 0.35, 0.3);  // grey
//
//   // Background color.
//   bg_color = RGBColor(157 / 255.0, 245 / 255.0, 239 / 255.0);
//
//   // Camera and sampler.
//   set_camera(new Perspective(0, 0, 160));
//   sampler_ptr = new Simple(camera_ptr, &vplane);
//
//   add_light(new PointLight(Point3D(100, 50,100), RGBColor(1.0, 1.0, 1.0), 1.0));
//
//    Sphere* s = new Sphere(Point3D(0, -40, -200), 140);
//    s->set_material(new GlossySpec(RGBColor(235, 173, 99) / 255.0, 1.0, 1.0, 2.0));
//    add_geometry(s);
//
//    Plane* p = new Plane(Point3D(0,-100,0), Vector3D(0,100,0));
//    p->set_material(new Transparent(RGBColor(1.0, 0.9, 0.8), 1.5));
//    add_geometry(p);
// }
//
