//
// Created by QYF on 2019/3/17.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,src_gray,drawImg;
int threshold_v = 170;
int threshold_max = 255;
const char* output_win = "rectangle-demo";
RNG rng(12345);
void contours_callback(int,void*);
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\yuan.png)");
    assert(!src.empty());

    cvtColor(src,src_gray,COLOR_BGR2GRAY);
    blur(src_gray,src_gray,Size(3,3),Point(-1,-1),BORDER_DEFAULT);

    const char* title = "input image";
    contours_callback(0, nullptr);
    createTrackbar(title,output_win,&threshold_v,threshold_max,contours_callback);


    waitKey(0);
    destroyAllWindows();
    return 0;
}
void contours_callback(int,void*){
    Mat threshold_output;
    threshold(src_gray,threshold_output,threshold_v,threshold_max,THRESH_BINARY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(threshold_output,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

    //初始化数组大小
    vector<vector<Point>> contours_poly(contours.size());
    vector<Rect> boundRects(contours.size());
    vector<Point2f> centers(contours.size());
    vector<float> radius(contours.size());
        //倾斜矩形与最小椭圆
    vector<RotatedRect> minRects(contours.size());
    vector<RotatedRect> minEllipses(contours.size());

    //得到最小矩形与圆形的坐标信息
    for(size_t i=0;i<contours.size();i++){
        //从这些点得到闭合曲线，3表示跟原来点的最大距离，true表示是闭合的
        approxPolyDP(Mat(contours[i]),contours_poly[i],3,true);
        boundRects[i] = boundingRect(contours_poly[i]);
        minEnclosingCircle(contours_poly[i],centers[i],radius[i]);
        if(contours_poly[i].size()>5) {
            minRects[i] = minAreaRect(contours_poly[i]);
            minEllipses[i] = fitEllipse(contours_poly[i]);
        }
    }

    //绘制
    src.copyTo(drawImg);
    Point2f ptrs[4];
    for(size_t i=0;i<contours.size();i++){
        Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
        drawContours(drawImg,contours,(int)i,color,1,LINE_8,hierarchy,0,Point(0,0));
        //画矩形与圆
        rectangle(drawImg,boundRects[i],color,2,LINE_8);
        circle(drawImg,centers[i],(int)radius[i],color,2,LINE_8);

        if(!minEllipses.empty() && minEllipses.size()>5) {
            ellipse(drawImg, minEllipses[i], color, 2, LINE_8);
            //得到倾斜矩形的四个点
            minRects[i].points(ptrs);
            for (int j = 0; j < 4; j++) {
                line(drawImg, ptrs[j], ptrs[(j + 1) % 4], color, 2, LINE_8);
            }
        }
    }
    imshow(output_win,drawImg);
}