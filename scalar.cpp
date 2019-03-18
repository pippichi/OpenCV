//
// Created by QYF on 2019/3/12.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src, dst;
    src = imread(R"(E:\��Ƭ\ͷ��.jpg)");
    if (src.empty()) {
        cout << "�ļ�������..." << endl;
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
    cout<<"dst��ͨ����: "<<channels<<endl;
    printf("first pixel values:%d\n",*firstRow);

    //CV_8UC3 --> 8��ʾÿ��ͨ��ռ8λ��U��ʾ�޷��š�C��ʾChar���͡�3��ʾͨ����Ŀ��3���������Ҫ����ĸ������Ķ�Ӧͨ����Ŀһ�£�
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

    //������ά����cv::Mat::create
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