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

    Laplacian(dst,output,CV_16S,3);
    convertScaleAbs(output,output);

    //阈值化处理
    threshold(output,output,0,255,THRESH_OTSU | THRESH_BINARY);

    imshow("output",output);


    waitKey(0);
    destroyAllWindows();
    return 0;
}