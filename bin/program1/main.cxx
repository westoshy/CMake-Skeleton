#include <mylib/hoge/hoge_test.hxx>
#include <mylib/fuga/fuga_test.hxx>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

int main(void)
{
  cv::Mat test;
  cv::xfeatures2d::SIFT sift;
  test = cv::imread("../../data/lenna.ppm");
  if (test.empty()) {
    std::cout << "error";
    std::cin.get(); std::cin.get();
  }
  std::cout << "program 1" << std::endl;
  hoge_test();
  fuga_test();
  return 0;
}