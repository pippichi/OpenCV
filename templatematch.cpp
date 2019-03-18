//
// Created by QYF on 2019/3/17.
//
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,temp,dst;
int match_method = TM_SQDIFF;
int max_track = 5;
const char* INPUT_I = "input image";
const char* OUTPUT_I = "output image";
const char* match_t = "template match-demo";
void match_demo(int,void*);
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\test4.png)");
    temp = imread(R"(C:\Users\Administrator\Desktop\test7.png)");
    assert(!src.empty());
    assert(!temp.empty());
    imshow(INPUT_I,temp);

    const char* track_title = "Match Algo Type: ";
    match_demo(0, nullptr);
    createTrackbar(track_title,match_t,&match_method,max_track,match_demo);

    waitKey(0);
    destroyAllWindows();
    return 0;
}

void match_demo(int,void*){
    int result_rows = src.rows - temp.rows + 1;
    int result_cols = src.cols - temp.cols + 1;
    Mat result(result_cols,result_rows,CV_32FC1);


    matchTemplate(src,temp,result,match_method,Mat());
    normalize(result,result,0,1,NORM_MINMAX,-1,Mat());

    //获取最大/最小值点
    double minValue,maxValue;
    Point minLoc,maxLoc;
    Point matchLoc;
    src.copyTo(dst);
    minMaxLoc(result,&minValue,&maxValue,&minLoc,&maxLoc,Mat());
    if(match_method==TM_SQDIFF||match_method==TM_SQDIFF_NORMED){
        matchLoc = minLoc;
    }else{
        matchLoc = maxLoc;
    }
    result.convertTo(result,CV_8UC1);
    rectangle(dst,matchLoc,Point(matchLoc.x+temp.cols,matchLoc.y+temp.rows),Scalar::all(0),2,LINE_AA);
    rectangle(result,matchLoc,Point(matchLoc.x+temp.cols,matchLoc.y+temp.rows),Scalar::all(0),2,LINE_AA);

//    imshow(OUTPUT_I,result);
    imshow(match_t,dst);
}