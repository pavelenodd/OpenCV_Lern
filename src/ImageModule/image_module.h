#pragma once
#include <iostream>
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
  cv::VideoCapture video_;  // Переменная для работы с видео
  cv::Mat frame_;  // Переменная для хранения кадров
  int slider_position_ = 0;  // Переменная для хранения позиции слайдера
  int run_flag_ = 1;  // Переменная для запуска видео
  int dontset_ = 0;  // Флаг для предотвращения изменения позиции слайдера

 private:
  // Статическая функция для обработки изменения положения слайдера
  static void On_TrackbarSlider(int pos, void* userdata) {
    VideoModule* self = static_cast<VideoModule*>(userdata);
    self->video_.set(cv::CAP_PROP_POS_FRAMES, pos);
    if (!self->dontset_) {
      self->run_flag_ = 1;
    }
    self->dontset_ = 0;
  }

 public:
  VideoModule(std::string L_path) {
    video_ = cv::VideoCapture(L_path);  // Открытие видео файла
    cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);  // Создание окна
    int frames = video_.get(cv::CAP_PROP_FRAME_COUNT);
    cv::createTrackbar("Frame", "Video", &slider_position_, frames,
                       On_TrackbarSlider, this);  // Создание слайдера
  }

  // Метод для отображения видео
  void Show() {
    while (true) {
      if (run_flag_ != 0) {
        video_ >> frame_;  // Захват следующего кадра
        if (frame_.empty()) {
          break;  // Выход из цикла, если кадры закончились
        }
        int current_pos = video_.get(cv::CAP_PROP_POS_FRAMES);
        dontset_ = 1;
        cv::setTrackbarPos("Frame", "Video",
                           current_pos);  // Обновление позиции слайдера

        cv::imshow("Video", frame_);  // Отображение кадра

        run_flag_ = -1;  // Остановка воспроизведения
      }
      char c = cv::waitKey(10);
      if (c == 'r') {  //  Старт воспроизведения при нажатии 'r'
        run_flag_ = 1;
      }
      if (c == 's') {  // Остановка воспроизведения при нажатии 's'
        run_flag_ = 0;
      }
      if (c == 27) {  // Выход при нажатии ESC
        break;
      }
    }
  }
};
