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
//        //Ч��̫��Ӳ
//        add(src,dst,output,Mat());

//        //���
//        multiply(src,dst,output,1.0);

        //���������addWeighted
        addWeighted(src,alpha,dst,(1-alpha),0,output);

        imshow("src", src);
        imshow("dst", dst);
        imshow("output",output);
    }else{
        cout << "���ܺϲ�" << endl;
        return -1;
    }

    waitKey(0);
    destroyAllWindows();
    return 0;
}