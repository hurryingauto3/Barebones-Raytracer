////  Credit: Matthew Calligaro <matthewcalligaro@hotmail.com>
//
// #include "../cameras/Parallel.hpp"
// #include "../cameras/Perspective.hpp"
// #include "../geometry/Plane.hpp"
// #include "../geometry/Sphere.hpp"
// #include "../geometry/Triangle.hpp"
// #include "../materials/GlossySpec.hpp"
// #include "../materials/TingedMirror.hpp"
// #include "../samplers/Simple.hpp"
// #include "../utilities/Constants.hpp"
// #include "../world/World.hpp"
// #include "../lights/PointLight.hpp"
// #include "../lights/DirectionalLight.hpp"
// #include "../tracers/ReflecTracer.hpp"
//
// void World::build(void) {
//    View plane
//   int n = 100;
//   vplane.top_left.x = -n;
//   vplane.top_left.y = n + 400;
//   vplane.top_left.z = 80;
//   vplane.bottom_right.x = n;
//   vplane.bottom_right.y = -n + 400;
//   vplane.bottom_right.z = 80;
//   vplane.hres = 400;
//   vplane.vres = 400;
//
//    colors
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
//    Background color.
//   bg_color = RGBColor(0.69, 1.0, 0.97);
//    tracer = new ReflecTracer(*this, 20);
//    Camera and sampler.
//   set_camera(new Perspective(0, 400, 160));
//   sampler_ptr = new Simple(camera_ptr, &vplane);
//
//   add_light(new DirectionalLight(Vector3D(0,-1,0), RGBColor(1.0, 1.0, 1.0), 1.0));
//
//   Point3D SphereCenter = Point3D(0, 0, -1000);
//
//    Sphere* s = new Sphere(SphereCenter, 70);
//    s->set_material(new GlossySpec(RGBColor(1.00,0.83,0.57), 0.8, 0.2, 4));
//    add_geometry(s);
//
//    Plane* p;
//    p = new Plane(Point3D(200,0,SphereCenter.z -100), Point3D(SphereCenter.x, SphereCenter.y, SphereCenter.z - 80) - Point3D(200,0,SphereCenter.z-100));
//    p->set_material(new TingedMirror(RGBColor(1.0, 0.99, 0.81)));
//    add_geometry(p);
//
//    p = new Plane(Point3D(-200,0,SphereCenter.z-100), Point3D(SphereCenter.x, SphereCenter.y, SphereCenter.z - 80) - Point3D(-200,0,SphereCenter.z-100));
//    p->set_material(new TingedMirror(RGBColor(1.0, 0.81, 0.81)));
//    add_geometry(p);
//
//    p = new Plane(Point3D(0,-200,0), Vector3D(0,1,0));
//    p->set_material(new GlossySpec(RGBColor(0.8, 0.1, 0.8), 0.8, 0.2, 4));
//    add_geometry(p);
//
// }
//
