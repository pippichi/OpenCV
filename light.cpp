//
// Created by QYF on 2019/3/13.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst;
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");
    if(!src.data){
        cout << "cannot find the pic"<<endl;
        return -1;
    }
    char *input_win = const_cast<char *>("input_image");
    imshow(input_win,src);

    //contract and brightness changes
    int height = src.rows;
    int width = src.cols;
    dst = Mat::zeros(src.size(),src.type());
    float alpha = 1.5;
    float beta = 30;
    //转化为3f的数据
    src.convertTo(src,CV_32F);
    for(int row=0;row<height;row++){
        for(int col=0;col<width;col++){
            if(src.channels()==1){
                float v = src.at<uchar>(row,col);
                dst.at<uchar>(row,col) = saturate_cast<uchar>(v * alpha + beta);
            }else if(src.channels()==3){
                float b = src.at<Vec3f>(row,col)[0];
                float g = src.at<Vec3f>(row,col)[1];
                float r = src.at<Vec3f>(row,col)[2];

                dst.at<Vec3b>(row,col)[0] = saturate_cast<uchar>(alpha * b + beta);
                dst.at<Vec3b>(row,col)[1] = saturate_cast<uchar>(alpha * g + beta);
                dst.at<Vec3b>(row,col)[2] = saturate_cast<uchar>(alpha * r + beta);
            }
        }
    }
    imshow("dst",dst);

    waitKey(0);
    destroyAllWindows();
    return 0;
}