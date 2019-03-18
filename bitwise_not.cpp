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
    if(src.empty()){
        cout << "cannot find the pic"<<endl;
        return -1;
    }
    imshow("input", src);

    //单层的操作
    cvtColor(src,dst,COLOR_BGR2GRAY);
    imshow("gray",dst);
    int height = dst.rows;
    int width = dst.cols;
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            int gray = dst.at<uchar>(row,col);
            dst.at<uchar>(row,col) = static_cast<uchar>(255 - gray);
        }
    }
    imshow("output", dst);

    //多层的操作
    Mat multi;
    multi.create(src.size(),src.type());
    height = multi.rows;
    width = multi.cols;
    int channels = multi.channels();
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(channels==1){
                int gray = multi.at<uchar>(row,col);
                multi.at<uchar>(row,col) = static_cast<uchar>(255 - gray);
            }else if(channels==3){
                int b = src.at<Vec3b>(row,col)[0];
                int g = src.at<Vec3b>(row,col)[1];
                int r = src.at<Vec3b>(row,col)[2];
                multi.at<Vec3b>(row,col)[0] = static_cast<uchar>(255 - b);
                multi.at<Vec3b>(row,col)[1] = static_cast<uchar>(255 - g);
                multi.at<Vec3b>(row,col)[2] = static_cast<uchar>(255 - r);

                //转灰度
                dst.at<uchar>(row,col) = (uchar) max(r, max(g, b));
            }
        }
    }
    imshow("gray_dst",dst);
    imshow("multi",multi);

    //替代上述两种方法的简便操作
    Mat normal;
    normal.create(src.size(),src.type());
    bitwise_not(src,normal);
    imshow("normal",normal);
    //imwrite(R"(C:\Users\Administrator\Desktop\5.jpg)",normal);

    waitKey(0);
    destroyAllWindows();
    return 0;
}