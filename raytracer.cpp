#include <iostream>
#include <vector>

#include "materials/Cosine.hpp"
#include "samplers/Sampler.hpp"

#include "utilities/Image.hpp"
#include "utilities/RGBColor.hpp"
#include "utilities/Ray.hpp"
#include "utilities/ShadeInfo.hpp"
#include "AccStr/BVH.hpp"
#include "AccStr/Acceleration.hpp"
#include "world/World.hpp"
#include "world/ViewPlane.hpp"
#include "tracers/BasicTracer.hpp"
#include "tracers/ReflecTracer.hpp"
#include "tracers/Tracer.hpp"

int main(int argc, char **argv) {
  World world;
  world.build();
  world.set_acceleration(new BVH(&world));
  Sampler *sampler = world.sampler_ptr;
  ViewPlane &viewplane = world.vplane;
  Image image(viewplane);

  std::vector<Ray> rays;
  for (int x = 0; x < viewplane.hres; x++) {   // across.
    for (int y = 0; y < viewplane.vres; y++) { // down.
      // Get rays for the pixel from the sampler. The pixel color is the
      // weighted sum of the shades for each ray.
      RGBColor pixel_color(0);
      rays = sampler->get_rays(x, y);
      for (const auto &ray : rays) {
        float weight = ray.w; // ray weight for the pixel.
        ShadeInfo sinfo = world.tracer->hit_objects(ray);
        if (sinfo.hit) {
          pixel_color += weight * world.tracer->shade(sinfo);
//          pixel_color.to_string();
        }
        else{
          pixel_color += weight * world.bg_color;
        }
      }
      // Save color to image.
        image.set_pixel(x, y, pixel_color);
      // std::cout << pixel_color << "\n";
    }
  }
  // Write image to file.
  image.write_ppm("scene.ppm");

  std::cout << "Wrote image.\n";

  return 0;
}



