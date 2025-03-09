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

//由于dlib和opencv中有相当一部分类同名，故不能同时对它们使用using namespace，否则会出现一些莫名其妙的问题
//using namespace dlib;
using namespace std;
//using namespace cv;

/*
    这里记得用的时候要在命令行使用 ,如
        ffface.exe D:/OpenCV_images/c456.png
    直接调试的话会找不到图片的
                                        --困扰了很久的小狙提醒你
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
