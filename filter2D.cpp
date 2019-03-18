//
// Created by QYF on 2019/3/12.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst;
    src = imread(R"(E:\照片\头像.jpg)");
    imshow("input", src);

//    int cols = (src.cols - 1) * src.channels();
//    int offSets = src.channels();
//    int rows = src.rows;
//    dst = Mat::zeros(src.size(),src.type());
//    for(int row=1;row<rows-1;row++){
//        const uchar* previous = src.ptr<uchar>(row-1);
//        const uchar* current = src.ptr<uchar>(row);
//        const uchar* next = src.ptr<uchar>(row+1);
//        auto * output = dst.ptr<uchar>(row);
//        for(int col=offSets;col<cols;col++){
//            output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offSets] + current[col + offSets] + previous[col] + next[col]));
//        }
//    }

    //一下操作可以替代以上所有操作
    //计时
    double start = getTickCount();
    Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
    filter2D(src,dst,src.depth(),kernel);
    double timeConsume = (getTickCount()-start)/getTickFrequency();
    printf("所需要的时间是:%.2f\n",timeConsume);

    imshow("output", dst);
    waitKey(0);
    destroyAllWindows();
    return 0;
}