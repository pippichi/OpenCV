//
// Created by QYF on 2019/3/13.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst,output;
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");

    assert(!src.empty());
    imshow("input",src);

    //ÖÐÖµÂË²¨
//    medianBlur(src,dst,3);

    //Ë«±ßÂË²¨
    bilateralFilter(src,dst,5,100,3);
    imshow("output",dst);

    Mat resultImage;
    Mat kernel = (Mat_<int>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
    filter2D(dst,resultImage,dst.depth(),kernel,Point(-1,-1),0);
    imshow("output2",dst);

    waitKey(0);
    destroyAllWindows();
    return 0;
}