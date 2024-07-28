#pragma once
#include <opencv2/highgui.hpp>
#include <string>

class ImageModule {
 private:
  cv::Mat image_;

 protected:
 public:
  ImageModule(std::string L_path) { image_ = cv::imread(L_path); }

  void show() {
    cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);  // создание окна
    cv::imshow("Image", image_);  // отображение изображения
    cv::waitKey(0);  // ожидание нажатия клавиши
    cv::destroyWindow("Image");  // закрытие окна
  }
};
