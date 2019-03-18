//
// Created by QYF on 2019/3/16.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst_gray,dst,output;
    src = imread(R"(C:\Users\Administrator\Desktop\test1.png)");
    assert(!src.empty());

    //extract edge
    Canny(src,dst_gray,130,200);
    cvtColor(dst_gray,dst,COLOR_GRAY2BGR);
    imshow("dst",dst);

    //霍夫直线检测获取点集合
    vector<Vec4f> plines;
    HoughLinesP(dst_gray,plines,1,CV_PI/180.0,20,0,10);

    Scalar color = Scalar(0,0,255);
    for(size_t i=0;i<plines.size();i++){
        Vec4f hline = plines[i];
        line(dst,Point((int)hline[0],(int)hline[1]),Point((int)hline[2],(int)hline[3]),color,2,LINE_AA);
    }
    imshow("output",dst);
    waitKey(0);
    destroyAllWindows();
    return 0;
}