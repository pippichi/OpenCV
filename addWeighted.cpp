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
    double alpha = 0.5;
    if(src.rows==dst.rows && src.cols==dst.cols){
//        //效果太生硬
//        add(src,dst,output,Mat());

//        //相乘
//        multiply(src,dst,output,1.0);

        //所以最好用addWeighted
        addWeighted(src,alpha,dst,(1-alpha),0,output);

        imshow("src", src);
        imshow("dst", dst);
        imshow("output",output);
    }else{
        cout << "不能合并" << endl;
        return -1;
    }

    waitKey(0);
    destroyAllWindows();
    return 0;
}