#include <iostream>
#include <string>

#include "ImageModule/image_module.h"

int main() {
  std::cout << "Enter path to video: ";
  std::string path = "E:\\Pets_pr\\OpenCV_Lern\\test\\test_wideo.webm";
  VideoModule img(path);
  img.Show();
  return 0;
}
