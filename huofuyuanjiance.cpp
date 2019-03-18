//
// Created by QYF on 2019/3/16.
//


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst_gray,dst,output;
    src = imread(R"(C:\Users\Administrator\Desktop\yuan.png)");
    assert(!src.empty());

    //中值滤波去噪
    medianBlur(src,dst,3);
    cvtColor(dst,dst_gray,COLOR_BGR2GRAY);

    //霍夫圆检测
    vector<Vec3f> pcircles;
    HoughCircles(dst_gray,pcircles,HOUGH_GRADIENT,1,10,100,30,5,50);
    src.copyTo(output);
    for (auto cc : pcircles) {
        circle(output,Point((int)cc[0],(int)cc[1]),(int)cc[2],Scalar(0,0,255),2,LINE_AA);
        circle(output,Point((int)cc[0],(int)cc[1]),2,Scalar(125,200,225),2,LINE_AA);
    }
    imshow("output",output);

    waitKey(0);
    destroyAllWindows();
    return 0;
}