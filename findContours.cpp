//
// Created by QYF on 2019/3/17.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,dst;
const char* OUTPUT_WIN = "findContours-demo";
int threshold_value = 100;
int threshold_max = 255;
RNG rng(12345);
void demo_contours(int,void*);
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\yuan.png)");
    assert(!src.empty());

    cvtColor(src,src,COLOR_BGR2GRAY);
    const char* trackbar_label = "Threshold Value: ";
    demo_contours(0,nullptr);
    createTrackbar(trackbar_label,OUTPUT_WIN,&threshold_value,threshold_max,demo_contours);


    waitKey(0);
    destroyAllWindows();
    return 0;
}

void demo_contours(int,void*){
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    Canny(src,dst,threshold_value,threshold_value*2,3,false);
    //默认Point(0,0)
    findContours(dst,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

    Mat drawImg = Mat::zeros(dst.size(),CV_8UC3);
    for(size_t i=0;i<contours.size();i++){
        Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
        //默认Point(0,0)
        drawContours(drawImg,contours,(int)i,color,1,LINE_8,hierarchy,0,Point(0,0));
    }
    imshow(OUTPUT_WIN,drawImg);
}