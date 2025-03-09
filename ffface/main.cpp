#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/gui_widgets.h>
#include <dlib/image_io.h>
#include <iostream>
#include <dlib/opencv.h>
#include "opencv2/opencv.hpp"
#include <vector>
#include <ctime>
#include "face.h"

//����dlib��opencv�����൱һ������ͬ�����ʲ���ͬʱ������ʹ��using namespace����������һЩĪ�����������
//using namespace dlib;
using namespace std;
//using namespace cv;

/*
    ����ǵ��õ�ʱ��Ҫ��������ʹ�� ,��
        ffface.exe D:/OpenCV_images/c456.png
    ֱ�ӵ��ԵĻ����Ҳ���ͼƬ��
                                        --�����˺ܾõ�С��������
*/


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "you should specified a picture!" << std::endl;
        return 0;
    }

    cv::Mat frame = cv::imread(argv[1]);
    cv::Mat dst;

    faceDetect obj1;
    obj1.dlib_get_character(frame, dst);

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
