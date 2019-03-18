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

    int top = static_cast<int>(0.05 * src.rows);
    int bottom = static_cast<int>(0.05 * src.rows);
    int left = static_cast<int>(0.05 * src.cols);
    int right = static_cast<int>(0.05 * src.cols);
    RNG rng(12345);
    int borderType = BORDER_DEFAULT;

    int c = 0;
    while(true){
        c = waitKey(500);
        if((char)c==27){
            break;
        }else if((char)c=='r'){
            borderType = BORDER_REPLICATE;
        }else if((char)c=='w'){
            borderType = BORDER_WRAP;
        }else if((char)c=='c'){
            borderType = BORDER_CONSTANT;
        }
        Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
        copyMakeBorder(src,dst,top,bottom,left,right,borderType,color);
        imshow("dst",dst);
        GaussianBlur(src,output,Size(5,5),0,0,borderType);
        imshow("output",output);
    }

    destroyAllWindows();
    return 0;
}
