//
// Created by QYF on 2019/3/15.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/**
 * 还可以上网自行搜索哪些算子好用
 * @param args
 * @param argv
 * @return
 */
int main(int args,char** argv) {
    Mat src,dst,kernel;
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");
    assert(!src.empty());

    int c = 0;
    int index = 0;
    int ksize;
    while(true){
        c = waitKey(500);
        if((uchar)c == 27){// ESC键
            break;
        }
        ksize = 4 + (index%5)*2 + 1;
        kernel = Mat::ones(Size(ksize,ksize),CV_32F) / (float)(ksize*ksize);
        filter2D(src,dst,-1,kernel,Point(-1,-1),0.0);
        index++;
        imshow("output",dst);
    }

    destroyAllWindows();
    return 0;
}