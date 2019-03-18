//
// Created by QYF on 2019/3/15.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,gray_src,output;
//设置阈值参数
int threshold_value = 127;
int threshold_max = 255;
//设置阈值类型参数
int thresholds = 4;
int current_threshold = 2;

const char* output_title = "binary image";
void Threshold_Demo(int,void*);

/**
 * 注意！：只能是8位单通道可以做，三通道不行
 * @param args
 * @param argv
 * @return
 */
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");
    assert(!src.empty());

    imshow("input",src);
    cvtColor(src,gray_src,COLOR_BGR2GRAY);
    Threshold_Demo(0, nullptr);
    createTrackbar("Threshold Value: ",output_title,&threshold_value,threshold_max,Threshold_Demo);
    createTrackbar("Threshold type: ",output_title,&current_threshold,thresholds,Threshold_Demo);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
void Threshold_Demo(int,void*){
    //THRESHOLD_BINARY、THRESHOLD_BINARY_INV、THRESHOLD_TRUNC、THRESHOLD_TOZERO、THRESHOLD_TOZERO_INV

    //手动设置阈值
//    threshold(gray_src,output,threshold_value,threshold_max,current_threshold);
    //自动计算阈值
//    threshold(gray_src,output,0,255,THRESH_OTSU | current_threshold);
    //三角法取阈值（根据直方图自动计算阈值）
    threshold(gray_src,output,0,255,THRESH_TRIANGLE | current_threshold);
    imshow(output_title,output);
};