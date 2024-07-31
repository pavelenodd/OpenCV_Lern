#pragma once
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
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
class VideoModule {
 private:
  cv::VideoCapture video_;
  cv::Mat frame_;

 public:
  VideoModule(std::string L_path) { video_ = cv::VideoCapture(L_path); }
  void show() {
    cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);  // создание окна
    while (true) {
      video_ >> frame_;
      if (frame_.empty()) {
        break;
      }
      cv::imshow("Video", frame_);  // отображение изображения
      if (cv::waitKey(33) >= 0) {
        break;
      }
    }

    cv::waitKey(0);  // ожидание нажатия клавиши
    cv::destroyWindow("Video");  // закрытие окна
  }
};