#include <opencv2/core/version.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    bool showWindow = false;  // 默认仅终端打印；加 --window 才弹窗
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--window" || a == "-w") showWindow = true;
    }

    // 版本打印：头文件宏 CV_VERSION 与链接库运行时版本应一致
    std::cout << "OpenCV " << CV_VERSION << std::endl;
    std::cout << "C++ demo | headers "
              << CV_VERSION_MAJOR << "." << CV_VERSION_MINOR << "." << CV_VERSION_REVISION
              << " | runtime " << cv::getVersionString() << std::endl;

    if (!showWindow) return 0;

    const int W = 860, H = 360;
    cv::Mat canvas(H, W, CV_8UC3, cv::Scalar(30, 30, 34));

    cv::putText(canvas, "OpenCV " + cv::getVersionString(), cv::Point(48, 120),
                cv::FONT_HERSHEY_SIMPLEX, 1.7, cv::Scalar(90, 220, 120), 3, cv::LINE_AA);

    std::string compiler = "compiler: g++ " + std::to_string(__GNUC__) + "." +
                           std::to_string(__GNUC_MINOR__) + "." + std::to_string(__GNUC_PATCHLEVEL__);
    cv::putText(canvas, "Language: C++  (OpenCV C++ API)", cv::Point(48, 190),
                cv::FONT_HERSHEY_SIMPLEX, 0.85, cv::Scalar(235, 235, 235), 2, cv::LINE_AA);
    cv::putText(canvas, compiler + "  |  Ubuntu 22.04.5 LTS (WSL2)", cv::Point(48, 245),
                cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(170, 175, 185), 1, cv::LINE_AA);
    cv::putText(canvas, "Press any key to close", cv::Point(48, 315),
                cv::FONT_HERSHEY_SIMPLEX, 0.6, cv::Scalar(120, 125, 135), 1, cv::LINE_AA);

    const char* win = "OpenCV version - C++";
    cv::namedWindow(win, cv::WINDOW_AUTOSIZE);
    cv::moveWindow(win, 80, 40);
    cv::imshow(win, canvas);
    std::cout << "window shown: " << win << " (press any key in the window to close)" << std::endl;
    cv::waitKey(0);
    cv::destroyWindow(win);
    return 0;
}
