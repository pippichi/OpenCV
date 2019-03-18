//
// Created by QYF on 2019/3/16.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst_gray,dst,output;
    src = imread(R"(C:\Users\Administrator\Desktop\yuan.png)");
    assert(!src.empty());
    imshow("input",src);
    //分通道显示
    vector<Mat> bgr;
    split(src,bgr);
//    imshow("bgr[0]",bgr_planes[0]);

    int histSize = 256;
    float range[] = {0,256};
    const float* histRange = {range};
    Mat b_hist,g_hist,r_hist;
    //直方图计算
    calcHist(&bgr[0],1, nullptr,Mat(),b_hist,1,&histSize,&histRange,true,false);
    calcHist(&bgr[1],1, nullptr,Mat(),g_hist,1,&histSize,&histRange,true,false);
    calcHist(&bgr[2],1, nullptr,Mat(),r_hist,1,&histSize,&histRange,true,false);

    //归一化
    int hist_h = 400;
    int hist_w = 512;
    int bin_w = hist_w / histSize;
    Mat histImage(hist_w,hist_h,CV_8UC3,Scalar(0,0,0));
    normalize(b_hist,b_hist,0,hist_h,NORM_MINMAX,-1,Mat());
    normalize(g_hist,g_hist,0,hist_h,NORM_MINMAX,-1,Mat());
    normalize(r_hist,r_hist,0,hist_h,NORM_MINMAX,-1,Mat());

    //render histogram chart
    for(int i=1;i<histSize;i++){
        line(histImage,Point((i-1)*bin_w,hist_h - cvRound(b_hist.at<float>(i-1))),Point(i*bin_w,hist_h - cvRound(b_hist.at<float>(i))),Scalar(255,0,0),2,LINE_AA);
        line(histImage,Point((i-1)*bin_w,hist_h - cvRound(g_hist.at<float>(i-1))),Point(i*bin_w,hist_h - cvRound(g_hist.at<float>(i))),Scalar(0,255,0),2,LINE_AA);
        line(histImage,Point((i-1)*bin_w,hist_h - cvRound(r_hist.at<float>(i-1))),Point(i*bin_w,hist_h - cvRound(r_hist.at<float>(i))),Scalar(0,0,255),2,LINE_AA);
    }
    imshow("output",histImage);

    waitKey(0);
    destroyAllWindows();
    return 0;
}