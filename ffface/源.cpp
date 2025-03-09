#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 检查 OpenCV 是否可以加载图像
    cv::Mat image = cv::imread("test.jpg");

    if (image.empty()) {
        std::cout << "无法读取图片！" << std::endl;
        return -1;
    }

    // 显示图片
    cv::namedWindow("OpenCV Test", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV Test", image);

    // 等待按键
    cv::waitKey(0);
    return 0;
}
