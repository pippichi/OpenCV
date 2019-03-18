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

    cvtColor(src,dst,COLOR_BGR2GRAY);
    imshow("input",dst);
    //直方图均衡化
    equalizeHist(dst,output);
    imshow("output",output);

    waitKey(0);
    destroyAllWindows();
    return 0;
}