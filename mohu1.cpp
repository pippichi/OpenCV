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
    dst = imread(R"(C:\Users\Administrator\Desktop\2.jpg)");
    assert(!src.empty());
    assert(!dst.empty());

    imshow("input",src);
    //Size()中的两个数都是奇数，以下1表示x轴模糊，9表示y轴模糊
    //均值滤波
    blur(src,dst,Size(1,9),Point(-1,-1));
    imshow("output",dst);
    //高斯模糊因为是根据权重的模糊因此比上面这个模糊要清晰，还可以看到一些纹理
    //高斯滤波
    GaussianBlur(src,dst,Size(5,5),11,11);

    waitKey(0);
    destroyAllWindows();
    return 0;
}