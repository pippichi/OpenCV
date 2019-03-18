//
// Created by QYF on 2019/3/15.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat img,img_gray;

    img = imread(R"(C:\Users\Administrator\Desktop\test2.png)");
    assert(!img.empty());

    imshow("input",img);

    cvtColor(img,img_gray,COLOR_BGR2GRAY);
    equalizeHist(img_gray,img_gray);

    CascadeClassifier eye_Classifier;
    CascadeClassifier face_cascade;

    if(!eye_Classifier.load(R"(D:\opencv4.0\opencv\sources\data\haarcascades\haarcascade_eye.xml)")){
        cout << "load haarcascade_eye.xml failed" << endl;
        return 0;
    }

    if(!face_cascade.load(R"(D:\opencv4.0\opencv\sources\data\haarcascades\haarcascade_frontalface_alt.xml)")){
        cout << "load haarcascade_frontalface_alt.xml failed" << endl;
        return 0;
    }

    vector<Rect> eyeRect;
    vector<Rect> faceRect;

    eye_Classifier.detectMultiScale(img_gray,eyeRect,1.1,2,0|CASCADE_SCALE_IMAGE,Size(30,30));
    for(size_t eyeIdx=0;eyeIdx<eyeRect.size();eyeIdx++){
        rectangle(img,eyeRect[eyeIdx],Scalar(0,0,255));
    }
    
    face_cascade.detectMultiScale(img_gray,faceRect,1.1,2,0|CASCADE_SCALE_IMAGE,Size(30,30));
    for(size_t i=0;i<faceRect.size();i++){
        rectangle(img,faceRect[i],Scalar(0,0,255));
    }
    
    imshow("output",img);

    waitKey(0);
    destroyAllWindows();
    return 0;
}