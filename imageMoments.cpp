//
// Created by QYF on 2019/3/17.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,src_gray,dst;
int threshold_value = 80;
int threshold_max = 255;
const char* OUTPUT_WIN = "convex hull demo";
void Moments_demo(int,void*);
RNG rng(12345);
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\yuan.png)");
    assert(!src.empty());

    cvtColor(src,src_gray,COLOR_BGR2GRAY);
    GaussianBlur(src_gray,src_gray,Size(3,3),0,0);


    const char* title = "Threshold Value: ";
    Moments_demo(0, nullptr);
    createTrackbar(title,OUTPUT_WIN,&threshold_value,threshold_max,Moments_demo);

    waitKey(0);
    destroyAllWindows();
    return 0;
}

void Moments_demo(int,void*) {
    Mat canny_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    Canny(src_gray,canny_output,threshold_value,threshold_value*2,3,false);
    findContours(canny_output,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

    vector<Moments> contours_moments(contours.size());
    vector<Point2f> ccs(contours.size());
    for(size_t i=0;i<contours.size();i++){
        contours_moments[i] = moments(contours[i]);
        //计算矩的重心
        ccs[i] = Point((int)(contours_moments[i].m10 / contours_moments[i].m00), (int)(contours_moments[i].m01 / contours_moments[i].m00));
    }

//    Mat drawImg = Mat::zeros(src.size(),CV_8UC3);
    Mat drawImg;
    src.copyTo(drawImg);
    for(size_t i=0;i<contours.size();i++){
        if(contours[i].size()<30){
            continue;
        }
        Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
        printf("center point x: %f y: %f\n",ccs[i].x,ccs[i].y);
        printf("contours %d area: %.2f arcLength: %.2f\n\n",(int)i,contourArea(contours[i]),arcLength(contours[i],true));
        drawContours(drawImg,contours,(int)i,color,1,LINE_8,hierarchy,0,Point(0,0));
        circle(drawImg,ccs[i],2,color,2,LINE_8);
    }
    imshow(OUTPUT_WIN,drawImg);
}