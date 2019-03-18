//
// Created by QYF on 2019/3/17.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,src_gray,dst;
int threshold_value = 100;
int threshold_max = 255;
const char* OUTPUT_WIN = "convex hull demo";
void Threshold_CallBack(int,void*);
RNG rng(12345);
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\yuan.png)");
    assert(!src.empty());

    cvtColor(src,src_gray,COLOR_BGR2GRAY);
    blur(src_gray,src_gray,Size(3,3),Point(-1,-1),BORDER_DEFAULT);
    imshow("input",src_gray);

    const char* title = "Threshold: ";
    Threshold_CallBack(0, nullptr);
    createTrackbar(title,OUTPUT_WIN,&threshold_value,threshold_max,Threshold_CallBack);

    waitKey(0);
    destroyAllWindows();
    return 0;
}

void Threshold_CallBack(int,void*){
    Mat threshold_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    threshold(src_gray,threshold_output,threshold_value,threshold_max,THRESH_BINARY);
    findContours(threshold_output,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

    //凸包集合
    vector<vector<Point>> hull(contours.size());
    for(size_t i=0;i<contours.size();i++){
        convexHull(Mat(contours[i]),hull[i],false,true);
    }

    dst = Mat::zeros(threshold_output.size(),CV_8UC3);
    Mat temp_dst;
    dst.copyTo(temp_dst);
    for(size_t i=0;i<contours.size();i++){
        Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
        drawContours(dst,hull,(int)i,color,1,LINE_8,hierarchy,0,Point(0,0));
        drawContours(dst,contours,(int)i,color,1,LINE_8,hierarchy,0,Point(0,0));
    }
    imshow(OUTPUT_WIN,dst);
}