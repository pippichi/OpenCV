//
// Created by QYF on 2019/3/15.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst,kernel,kernel_y;
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");
    assert(!src.empty());

    imshow("input",src);

    //Robert X方向(-45度角差异)
    kernel = (Mat_<int>(2,2)<<1,0,0,-1);
    filter2D(src,dst,-1,kernel,Point(-1,-1),0.0);
    imshow("output",dst);

    //Robert Y方向(45度角差异)
    Mat y_dst;
    kernel_y = (Mat_<int>(2,2)<<0,1,-1,0);
    filter2D(src,y_dst,-1,kernel_y,Point(-1,-1),0.0);
    imshow("y_dst",y_dst);

    //Sobel X方向差异
    Mat sobel_x,s_kernel_x;
    s_kernel_x = (Mat_<int>(3,3)<<-1,0,1,-2,0,2,-1,0,1);
    filter2D(src,sobel_x,-1,s_kernel_x,Point(-1,-1),0.0);
    imshow("sobel_x",sobel_x);

    //Sobel Y方向差异
    Mat sobel_y,s_kernel_y;
    s_kernel_y = (Mat_<int>(3,3)<<-1,2,-1,0,0,0,1,2,1);
    filter2D(src,sobel_y,-1,s_kernel_y,Point(-1,-1),0.0);
    imshow("sobel_y",sobel_y);

    //拉普拉斯算子 全差异
    Mat lapulasi,lapulasi_kernel;
    lapulasi_kernel = (Mat_<int>(3,3)<<0,-1,0,-1,4,-1,0,-1,0);
    filter2D(src,lapulasi,-1,lapulasi_kernel,Point(-1,-1),0.0);
    imshow("lapulasi",lapulasi);

    waitKey(0);
    destroyAllWindows();
    return 0;
}