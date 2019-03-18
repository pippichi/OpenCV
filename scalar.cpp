//
// Created by QYF on 2019/3/12.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src, dst;
    src = imread(R"(E:\照片\头像.jpg)");
    if (src.empty()) {
        cout << "文件不存在..." << endl;
        return -1;
    }
    imshow("input", src);
    dst = Mat(src.size(), src.type());
    dst = Scalar(127,0,255);
    imshow("output",dst);

    int cols = src.cols;
    int rows = src.rows;
    cout << cols <<endl<< rows << endl;

    const uchar* firstRow = dst.ptr<uchar>(0);
    const int channels = dst.channels();
    cout<<"dst的通道数: "<<channels<<endl;
    printf("first pixel values:%d\n",*firstRow);

    //CV_8UC3 --> 8表示每个通道占8位、U表示无符号、C表示Char类型、3表示通道数目是3（这个数据要与第四个参数的对应通道数目一致）
    Mat M(3,3,CV_8UC3,Scalar(0,0,255));
    cout<<"M = "<<endl<<M<<endl;
    imshow("M",M);

    cvtColor(src,dst,COLOR_BGR2GRAY);
    Mat csrc,kernel;
    kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(src,csrc,src.depth(),kernel);
    imshow("csrc",csrc);

    Mat M2 = Mat::zeros(2,2,CV_8UC1);
    cout<<"M2 = "<<endl<<M2<<endl;
    Mat M3 = Mat::eye(2,2,CV_8UC1);
    cout<<"M3 = "<<endl<<M3<<endl;

    //创建多维数组cv::Mat::create
    /*int sz[3] = { 2,2,2 };
    Mat L(3, sz, CV_8SC1, Scalar::all(0));
    imshow("L", L);*/

    //M.create(int,int,type);	M = Scalar(size);
    Mat M4;
    M4.create(src.size(),src.type());
    M4 = Scalar(0,0,255);
    imshow("M4",M4);
    
    waitKey(0);
    destroyAllWindows();
    return 0;
}