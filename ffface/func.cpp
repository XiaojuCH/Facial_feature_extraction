#include "face.h"

void faceDetect::dlib_detect_demo1()
{

}

void faceDetect::line_one_face_detections(cv::Mat img, std::vector<dlib::full_object_detection> fs)
{
    int i, j;
    for (j = 0; j < fs.size(); j++)
    {
        cv::Point p1, p2;
        for (i = 0; i < 67; i++)
        {
            // �°͵����� 0 ~ 16
            //���üë 17 ~ 21
            //�ұ�üë 21 ~ 26
            //����     27 ~ 30
            //�ǿ�        31 ~ 35
            //����        36 ~ 41
            //����        42 ~ 47
            //�촽��Ȧ  48 ~ 59
            //�촽��Ȧ  59 ~ 67
            switch (i)
            {
            case 16:
            case 21:
            case 26:
            case 30:
            case 35:
            case 41:
            case 47:
            case 59:
                i++;
                break;
            default:
                break;
            }

            p1.x = fs[j].part(i).x();
            p1.y = fs[j].part(i).y();
            p2.x = fs[j].part(i + 1).x();
            p2.y = fs[j].part(i + 1).y();
            cv::line(img, p1, p2, cv::Scalar(0, 0, 255), 2, 4, 0);
        }
    }
}

void faceDetect::dlib_get_character(cv::Mat& frame, cv::Mat& dst)
{
    //��ȡ�Ҷ�ͼ
    cv::cvtColor(frame, dst, cv::COLOR_BGR2GRAY);

    //����dlib������ʶ����
    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();

    //����������״̽����
    dlib::shape_predictor sp;
    dlib::deserialize("C:\\Users\\Xiaoju\\source\\repos\\ffface\\ffface\\shape_predictor_68_face_landmarks.dat") >> sp;

    //Matת��Ϊdlib��matrix
    dlib::array2d<dlib::bgr_pixel> dimg;
    dlib::assign_image(dimg, dlib::cv_image<uchar>(dst));

    //��ȡһϵ��������������
    std::vector<dlib::rectangle> dets = detector(dimg);
    std::cout << "Number of faces detected: " << dets.size() << std::endl;

    if (dets.size() == 0)
        return;

    //��ȡ����������ֲ�
    std::vector<dlib::full_object_detection> shapes;
    int i = 0;
    for (i = 0; i < dets.size(); i++)
    {
        dlib::full_object_detection shape = sp(dimg, dets[i]); //��ȡָ��һ�������������״
        shapes.push_back(shape);
    }

    //ָ��ÿ����⵽��������λ��
    for (i = 0; i < dets.size(); i++)
    {
        //����������������
        cv::Rect r;
        r.x = dets[i].left();
        r.y = dets[i].top();
        r.width = dets[i].width();
        r.height = dets[i].height();
        cv::rectangle(frame, r, cv::Scalar(0, 0, 255), 1, 1, 0);
    }


    faceDetect::line_one_face_detections(frame, shapes);
    cv::imshow("frame", frame);
}

