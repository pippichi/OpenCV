//
// Created by QYF on 2019/3/16.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string convertToString(double d);
int main(int argc,char** argv){
    Mat base,test1,test2;
    Mat hsvbase,hsvtest1,hsvtest2;
    base = imread(R"(C:\Users\Administrator\Desktop\base.png)");
    test1 = imread(R"(C:\Users\Administrator\Desktop\test5.png)");
    test2 = imread(R"(C:\Users\Administrator\Desktop\test6.png)");
    assert(!test1.empty());
    assert(!test2.empty());
    assert(!base.empty());

    cvtColor(test1,hsvtest1,COLOR_BGR2HSV);
    cvtColor(base,hsvbase,COLOR_BGR2HSV);
    cvtColor(test2,hsvtest2,COLOR_BGR2HSV);

    int h_bins = 50,s_bins = 60;
    int histSize[] = {h_bins,s_bins};
    //hue values from 0 to 179,saturation from 0 to 255
    float h_ranges[] = {0,180};
    float s_ranges[] = {0,256};
    const float* ranges[] = {h_ranges,s_ranges};
    //Use the 0-th and 1-st channels
    int channels[] = {0,1};
    //多维Mat
    MatND hist_base;
    MatND hist_test1;
    MatND hist_test2;

    calcHist(&hsvbase,1,channels,Mat(),hist_base,2,histSize,ranges,true,false);
    normalize(hist_base,hist_base,0,1,NORM_MINMAX,-1,Mat());
    calcHist(&hsvtest1,1,channels,Mat(),hist_test1,2,histSize,ranges,true,false);
    normalize(hist_test1,hist_test1,0,1,NORM_MINMAX,-1,Mat());
    calcHist(&hsvtest2,1,channels,Mat(),hist_test2,2,histSize,ranges,true,false);
    normalize(hist_test2,hist_test2,0,1,NORM_MINMAX,-1,Mat());

    //进行计算（可以使用相关性计算、卡方计算、十字计算、巴氏距离计算）；返回值都为double类型
    double basebase = compareHist(hist_base,hist_base,HISTCMP_BHATTACHARYYA);
    double basetest1 = compareHist(hist_base,hist_test1,HISTCMP_BHATTACHARYYA);
    double basetest2 = compareHist(hist_base,hist_test2,HISTCMP_BHATTACHARYYA);
    double test1test2 = compareHist(hist_test1,hist_test2,HISTCMP_BHATTACHARYYA);
    printf("base compare with base correlation value :%f\n",basebase);
    printf("base compare with test1 correlation value :%f\n",basetest1);
    printf("base compare with test2 correlation value :%f\n",basetest2);
    printf("test1 compare with test2 correlation value :%f\n",test1test2);

    Mat test12;
    test2.copyTo(test12);
    putText(base,convertToString(basebase),Point(50,50),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
    putText(test1,convertToString(basetest1),Point(50,50),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
    putText(test2,convertToString(basetest2),Point(50,50),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
    putText(test12,convertToString(test1test2),Point(50,50),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);

    imshow("base",base);
    imshow("test1",test1);
    imshow("test2",test2);
    imshow("test12",test12);

    waitKey(0);
    destroyAllWindows();
    return 0;
}

string convertToString(double d){
    ostringstream os;
    if(os << d){
        return os.str();
    }
    return "invalid conversion";
}