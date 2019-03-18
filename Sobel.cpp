//
// Created by QYF on 2019/3/16.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst,output;
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");
    assert(!src.empty());

    GaussianBlur(src,dst,Size(3,3),0,0);
    cvtColor(dst,dst,COLOR_BGR2GRAY);

    //Sobel算子
    Mat xgrad,ygrad;
    Sobel(dst,xgrad,CV_16S,1,0,3);
    Sobel(dst,ygrad,CV_16S,0,1,3);

    //由于做出来的像素有时候是负数，因此需要处理成正数
    convertScaleAbs(xgrad,xgrad);
    convertScaleAbs(ygrad,ygrad);

    imshow("xgrad",xgrad);
    imshow("ygrad",ygrad);

    //平方开方（比较耗资源）
    addWeighted(xgrad,0.5,ygrad,0.5,0,output);
    imshow("output",output);
    //直接绝对值相加，相较而言效率更高
    Mat Absgrad = Mat(xgrad.size(),xgrad.type());
    int height = xgrad.cols;
    int width = xgrad.rows;
    for(int row=0;row<width;row++){
        for(int col=0;col<height;col++){
            int xg = xgrad.at<uchar>(row,col);
            int yg = ygrad.at<uchar>(row,col);
            int xy = xg + yg;
            Absgrad.at<uchar>(row,col) = saturate_cast<uchar>(xy);
        }
    }
    imshow("Absgrad",Absgrad);

    //Scharr算子
    Mat scharr_x,scharr_y,scharr_output;
    Scharr(dst,scharr_x,CV_16S,1,0);
    Scharr(dst,scharr_y,CV_16S,0,1);

    convertScaleAbs(scharr_x,scharr_x);
    convertScaleAbs(scharr_y,scharr_y);

    imshow("scharr_x",scharr_x);
    imshow("scharr_y",scharr_y);

    addWeighted(scharr_x,0.5,scharr_y,0.5,0,scharr_output);
    imshow("scharr_output",scharr_output);

    waitKey(0);
destroyAllWindows();
return 0;
}