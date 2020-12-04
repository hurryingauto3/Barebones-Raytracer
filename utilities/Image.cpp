#include "Image.hpp"

Image::Image(int hres, int vres){
    //Assign hres and vrex from parameters
    this->hres = hres;
    this->vres = vres;

    //Assign color pointer arrary
    this->colors = new RGBColor*[this->vres];
    //Assign color arrary
    for (int i=0; i<(this->vres); i++)
        colors[i] = new RGBColor[this->hres];
}

Image::Image(const ViewPlane &vp){
    //Assign hres and vrex from Viewplane
    this->hres = vp.get_hres();
    this->vres = vp.get_vres();

    //Assign color pointer arrary
    this->colors = new RGBColor*[this->vres];
    //Assign color arrary
    for (int i=0; i<(this->vres); i++)
        colors[i] = new RGBColor[this->hres];
}

Image::~Image(){

    for (int i = 0; i < this->vres; i++){
        //Delete pointers of each RGBcolor array
        delete [] this->colors[i];
    }
    //Delete color**
    delete [] this->colors;
}

void Image::set_pixel(int x, int y, const RGBColor& color){
    this->colors[x][y] = color;
}


void Image::write_ppm(std::string path) const{

  float maxrgb(0);

  for (int i = 0; i < this->vres; i++){

    for(int j = 0; j < this->hres; j++){
      //Find largest value in all the r,g,b values in the color array.
      float maxrgb1 = max_element(this->colors[i][j].r, this->colors[i][j].g, this->colors[i][j].b);
      if (maxrgb1 > maxrgb)
      maxrgb = maxrgb1;

    }
  }

  std::ofstream file(path);
  file << "P3" << "\n";
  file << hres << " " << vres << "\n";
  file << 255 << "\n";

  //Find scale using maxrgb
  double scale = 255/maxrgb;

  for (int i = 0; i < this->vres; i++){
    for(int j = 0; j < this->hres; j++){

      file
      //Write scaled r,g,b data to ppm file.
      << std::to_string(this->colors[j][i].r*scale) << " "
      << std::to_string(this->colors[j][i].g*scale) << " "
      << std::to_string(this->colors[j][i].b*scale) << " ";
    }
      file << "\n";
  }
  file.close();
}
