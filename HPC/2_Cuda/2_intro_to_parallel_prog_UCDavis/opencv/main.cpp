// To run: g++ main.cpp -o output `pkg-config --cflags --libs opencv4`

#include <iostream>
#include <opencv2/highgui.hpp>

int main(int argc, char** argv)
{
  cv::Mat image;
  // image = cv::imread("sample.jpeg" , CV_LOAD_IMAGE_COLOR);
  image = cv::imread("2021-05-01-113311.jpg", cv::IMREAD_COLOR);

  if (!image.data)
  {
    std::cout << "Could not open or find the image" << std::endl;
    return -1;
  }

  cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
  cv::imshow("Display window", image);

  cv::waitKey(0);
  return 0;
}
