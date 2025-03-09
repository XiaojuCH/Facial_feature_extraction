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

class faceDetect {
public:
	void dlib_detect_demo1();// nothing
	void line_one_face_detections(cv::Mat img, std::vector<dlib::full_object_detection> fs);
	void dlib_get_character(cv::Mat& frame, cv::Mat& dst);
};

