//
// Created by QYF on 2019/3/15.
//
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
/**
 * 提取步骤：
 * 1、转灰度
 * 2、转二值
 * 3、定义结构元素
 * 4、开操作提取水平与垂直线
 * @param args
 * @param argv
 * @return
 */
int main(int args,char** argv) {
    Mat src,dst;
    src = imread(R"(C:\Users\Administrator\Desktop\test3.png)");
    assert(!src.empty());

    cvtColor(src,dst,COLOR_BGR2GRAY);

    //二值图像
    Mat binImg;
    //可用函数：ADAPTIVE_THRESH_GAUSSIAN_C、ADAPTIVE_THRESH_MEAN_C
    adaptiveThreshold(dst,binImg,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,15,-2);
    imshow("input",binImg);

    //水平结构元素
    Mat hline = getStructuringElement(MORPH_RECT,Size(src.cols/16,1),Point(-1,-1));
    //垂直结构元素
    Mat vline = getStructuringElement(MORPH_RECT,Size(1,src.rows/16),Point(-1,-1));
//    erode(binImg,binImg,hline);
//    dilate(binImg,binImg,hline);
    morphologyEx(binImg,binImg,MORPH_OPEN,hline);

    bitwise_not(binImg,binImg);

    imshow("output",binImg);


    waitKey(0);
    destroyAllWindows();
    return 0;
}
