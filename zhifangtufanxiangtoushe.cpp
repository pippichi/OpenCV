//
// Created by QYF on 2019/3/17.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,hsv,hue;
int bins = 12;
void hist_and_backproject(int,void*);
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\test5.png)");
    assert(!src.empty());
    cvtColor(src,hsv,COLOR_BGR2HSV);

    hue.create(hsv.size(),hsv.depth());
    int nchannels[] = {0,0};
    //copy通道
    mixChannels(&hsv,1,&hue,1,nchannels,1);

    hist_and_backproject(0, nullptr);
    createTrackbar("Histogram bins: ","backProject",&bins,180,hist_and_backproject);



    waitKey(0);
    destroyAllWindows();
    return 0;
}

void hist_and_backproject(int,void*){
    float range[] = {0,180};
    const float* histrange[] = {range};
    Mat h_hist;
    calcHist(&hue,1, nullptr,Mat(),h_hist,1,&bins,histrange,true,false);
    normalize(h_hist,h_hist,0,255,NORM_MINMAX,-1,Mat());

    Mat backProject;
    calcBackProject(&hue,1, nullptr,h_hist,backProject,histrange,1,true);
    imshow("backProject",backProject);

    //绘制直方图
    int hist_h = 400,hist_w = 400;
    //bin_w意思就是计算出直方图中要画多少个直方。
    int bin_w = hist_w / bins;
    Mat histImage;
    histImage.create(hist_w,hist_h,CV_8UC3);
    histImage = Scalar(0,0,0);

    for(int i=1;i<=bins;i++){
        rectangle(histImage,Point((i-1)*bin_w,hist_h-cvRound(h_hist.at<float>(i-1)*hist_h/256)),Point(i*bin_w,hist_h),Scalar(0,0,255),-1,LINE_AA);
    }
    imshow("histogram",histImage);
}