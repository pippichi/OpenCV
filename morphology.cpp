//
// Created by QYF on 2019/3/15.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(int args,char** argv) {
    Mat src,dst;
    src = imread(R"(E:\照片\头像.jpg)");
    assert(!src.empty());

    imshow("input",src);
    
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));
    //开操作
//    morphologyEx(src,dst,MORPH_OPEN,kernel);
    //闭操作
//    morphologyEx(src,dst,MORPH_CLOSE,kernel);
    //形态学梯度(包括内部梯度（原图-腐蚀）,方向梯度（x和y方向上进行梯度计算得出的梯度）)
//    morphologyEx(src,dst,MORPH_GRADIENT,kernel);
    //顶帽
//    morphologyEx(src,dst,MORPH_TOPHAT,kernel);
    //黑帽
    morphologyEx(src,dst,MORPH_BLACKHAT,kernel);
    imshow("output",dst);
    
    waitKey(0);
    destroyAllWindows();
    return 0;
}