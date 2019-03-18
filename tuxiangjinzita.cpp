//
// Created by QYF on 2019/3/15.
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

    //降采样
    pyrDown(src,dst,Size(src.cols/2,src.rows/2));
    imshow("output",dst);
    //上采样
    pyrUp(dst,output,Size(dst.cols*2,dst.rows*2));
    imshow("up_output",output);

    //高斯不同(DOG)
    Mat gray_img,g1,g2,dogImg;
    cvtColor(src,gray_img,COLOR_BGR2GRAY);
    GaussianBlur(gray_img,g1,Size(5,5),0,0);
    GaussianBlur(g1,g2,Size(5,5),0,0);
    subtract(g1,g2,dogImg,Mat());

    //0-255最大最小归一化
    normalize(dogImg,dogImg,255,0,NORM_MINMAX);
    imshow("DOG img",dogImg);

    waitKey(0);
    destroyAllWindows();
    return 0;
}