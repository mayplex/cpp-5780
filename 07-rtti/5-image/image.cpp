/**
 * Writes a PPM image file.
 * 
 * Author: Erel Segal-Halevi.
 * Based on C code in RosettaCode: 
 * http://rosettacode.org/wiki/Category:C
 * 
 * Since: 2018-04
 */

#include <iostream>
#include <fstream>
using namespace std;

struct RGB {
  uint8_t red, green, blue;
public:
  RGB(): red(0), green(0), blue(0) {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};



int main() {
  const int dimx = 800, dimy = 800;
  ofstream imageFile("image.ppm", ios::out | ios::binary);
  imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
  RGB image[dimx*dimy];
  for (int j = 0; j < dimy; ++j)  {  // row
    for (int i = 0; i < dimx; ++i) { // column
      int ii = (i*256/800);
      int jj = (j*256/800);
      image[dimx*j+i].red = ii% (256);
      image[dimx*j+i].green = jj % (256);
      image[dimx*j+i].blue = ( (ii*ii+jj*jj) % 256);
    }
  }
  ///
  ///image processing
  ///
  //imageFile.write(&image, 3*dimx*dimy);         // compile error
  //imageFile << image;
  //compressedImage = compress(image);
  //imageFile.write((char*)(&image), 3*dimx*dimy);   // fine
  imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);  // fine
  imageFile.close();
  return 0;
}
