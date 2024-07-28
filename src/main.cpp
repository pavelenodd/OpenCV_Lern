#include <iostream>
#include <string>

#include "ImageModule/image_module.h"

int main() {
  std::cout << "Enter path to image: ";
  std::string path = "E:/Pets_pr/OpenCV_Lern/test/test_image.jpg";
  // std::cin >> path;
  ImageModule img(path);
  img.show();
  return 0;
}
