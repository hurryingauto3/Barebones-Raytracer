////  Credit: Matthew Calligaro <matthewcalligaro@hotmail.com>
//
// #include "../cameras/Parallel.hpp"
// #include "../cameras/Perspective.hpp"
// #include "../geometry/Plane.hpp"
// #include "../geometry/Sphere.hpp"
// #include "../geometry/Triangle.hpp"
// #include "../materials/GlossySpec.hpp"
// #include "../materials/TingedMirror.hpp"
// #include "../materials/Transparent.hpp"
// #include "../samplers/Simple.hpp"
// #include "../utilities/Constants.hpp"
// #include "../world/World.hpp"
// #include "../lights/PointLight.hpp"
// #include "../lights/DirectionalLight.hpp"
// #include "../geometry/Mesh.hpp"
// #include "../tracers/ReflecNoShadow.hpp"
//
// void World::build(void) {
////    View plane
//   tracer = new ReflecNoShadow(*this, 20);
//   int n = 100;
//   vplane.top_left.x = -n;
//   vplane.top_left.y = n;
//   vplane.top_left.z = 80;
//   vplane.bottom_right.x = n;
//   vplane.bottom_right.y = -n;
//   vplane.bottom_right.z = 80;
//   vplane.hres = 400;
//   vplane.vres = 400;
//
////    colors
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
////    Background color.
//   bg_color = RGBColor(0.69, 1.0, 0.97);
//
////    Camera and sampler.
//   set_camera(new Perspective(0, 0, 160));
//   sampler_ptr = new Simple(camera_ptr, &vplane);
//
//   add_light(new PointLight(Point3D(0,0,160), RGBColor(1.0, 1.0, 1.0), 1.0));
//
//    Mesh m("pyramid.obj");
//    m.read_obj();
//    m.set_material(new GlossySpec(RGBColor(1.0, 0.8, 0.1)));
//    m.populateInGeom(this);
//
//    Sphere* s;
//    s = new Sphere(Point3D(0, -140, -20), 70);
//    s->set_material(new GlossySpec(RGBColor(1.0, 0.99, 0.81), 0.8, 0.2, 3));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-200, -300, -500), 70);
//    s->set_material(new GlossySpec(RGBColor(0.9, 0.4, 0.9), 0.8, 0.2, 3));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(200, 200, -460), 300);
//    s->set_material(new TingedMirror(RGBColor(0.95, 0.95, 0.95)));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-50, -80, -80), 20);
//    s->set_material(new GlossySpec(RGBColor(0.95, 0.1, 0.1)));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-300, 750, 100), 500);
//    s->set_material(new TingedMirror(RGBColor(0.95, 0.95, 0.95)));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-700, 550, -860), 300);
//    s->set_material(new TingedMirror(RGBColor(0.95, 0.95, 0.95)));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-800, 50, -460), 300);
//    s->set_material(new TingedMirror(RGBColor(0.95, 0.95, 0.95)));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(500, 900, -1500), 400);
//    s->set_material(new TingedMirror(RGBColor(227, 148, 113)/ 255));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(50, 1100, -2700), 400);
//    s->set_material(new TingedMirror(RGBColor(227, 113, 148)/ 255));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-700, 900, -3000), 400);
//    s->set_material(new TingedMirror(RGBColor(170, 148, 170)/ 255));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-760, 2100, -3000), 400);
//    s->set_material(new GlossySpec(RGBColor(170, 220, 250)/ 255));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(6000, 1000, -6500), 5000);
//    s->set_material(new GlossySpec(RGBColor(191, 122, 207)/ 255));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(0, 3500, -25000), 20000);
//    s->set_material(new GlossySpec(RGBColor(156, 219, 162)/ 255));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(500, 900, -1500), 400);
//    s->set_material(new TingedMirror(RGBColor(227, 148, 113)/ 255));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-300, 50, -70), 70);
//    s->set_material(new GlossySpec(RGBColor(1.0, 0.99, 0.81), 0.8, 0.2, 3));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(300, 50, -70), 70);
//    s->set_material(new GlossySpec(RGBColor(1.0, 0.99, 0.81), 0.8, 0.2, 3));
//    add_geometry(s);
//
//    s = new Sphere(Point3D(-100, 50, -70), 70);
//    s->set_material(new GlossySpec(RGBColor(1.0, 0.99, 0.81), 0.8, 0.2, 3));
//    add_geometry(s);
//
//
//    Plane* p = new Plane(Point3D(0,-100,0), Vector3D(0,100,0));
//    p->set_material(new Transparent(RGBColor(0.9, 0.8, 0.81), 1.5));
//    add_geometry(p);
// }
//
