#include <iostream>
#include <string>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

int main() {
    std::cout << "OpenCV " << cv::getVersionString() << " (C++ / CMake build)" << std::endl;

    // 画一张图，走一遍 OpenCV 的 imgproc / imgcodecs 流程，验证库真的能用
    cv::Mat img(480, 640, CV_8UC3, cv::Scalar(45, 40, 40));
    cv::circle(img, cv::Point(320, 210), 120, cv::Scalar(0, 200, 255), -1, cv::LINE_AA);
    cv::putText(img, "OpenCV " + cv::getVersionString(), cv::Point(150, 400),
                cv::FONT_HERSHEY_SIMPLEX, 1.4, cv::Scalar(240, 240, 240), 3, cv::LINE_AA);

    cv::Mat blurred;
    cv::GaussianBlur(img, blurred, cv::Size(15, 15), 0);

    const std::string out = "out.png";
    if (!cv::imwrite(out, blurred)) {
        std::cerr << "imwrite failed: " << out << std::endl;
        return 1;
    }
    cv::Mat loaded = cv::imread(out);
    if (loaded.empty()) {
        std::cerr << "imread failed: " << out << std::endl;
        return 1;
    }
    cv::Scalar mean = cv::mean(loaded);
    std::cout << "saved " << out << " " << loaded.cols << "x" << loaded.rows
              << "  mean(B,G,R)=" << mean[0] << "," << mean[1] << "," << mean[2] << std::endl;
    return 0;
}
