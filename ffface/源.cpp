#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // ��� OpenCV �Ƿ���Լ���ͼ��
    cv::Mat image = cv::imread("test.jpg");

    if (image.empty()) {
        std::cout << "�޷���ȡͼƬ��" << std::endl;
        return -1;
    }

    // ��ʾͼƬ
    cv::namedWindow("OpenCV Test", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV Test", image);

    // �ȴ�����
    cv::waitKey(0);
    return 0;
}
