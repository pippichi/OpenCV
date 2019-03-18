//
// Created by QYF on 2019/3/18.
//

#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//图片数据名字：原图，灰度图，二值图，直方图
Mat src,src_gray,dst,src_equ;

static void on_trackbar(int,void*);

int main(int argc, char** argv) {
    //图片读入
    src = imread(R"(C:\Users\Administrator\Desktop\card.png)");

    //判断是否存在
    if (!src.data) {
        cout << "Image no find,error!" << endl;
    }

    cvtColor(src,src_gray,COLOR_BGR2GRAY);
    imshow("原图",src);

    int nThreshold = 150;
    on_trackbar(nThreshold,0);
    createTrackbar("graybar","二值图",&nThreshold,255,on_trackbar);


    waitKey(0);
    destroyAllWindows();
    return 0;
}

static void on_trackbar(int pos,void*){
    //二值化
    threshold(src_gray,dst,pos,255,THRESH_BINARY);
    imshow("二值图",dst);

    //直方均匀化
    equalizeHist(dst,src_equ);

    //识别轮廓
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(src_equ,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);

    //轮廓数量（可以没有）
    //int len = contours.size();
    //cout<<len<<endl;

    //将图拷贝，进行遍历图片每个像素
    Mat secImg = src_gray.clone();
    const int cols = secImg.cols;
    const int rows = secImg.rows;
    for(int j=0;j<rows;j++){
        auto *sdata = secImg.ptr<uchar>(j);
        for(int i=0;i<cols;i++){
            //判断是否在轮廓上或者外面
            if(pointPolygonTest(contours[0],Point(i,j),false)==-1){
                sdata[i] = 0;
            }
        }
    }

    Mat draw_img;
    src.copyTo(draw_img);
    for(size_t i=0;i<contours.size();i++){
        drawContours(draw_img,contours,(int)i,Scalar(0,255,255),2,LINE_8,hierarchy,0,Point(0,0));
    }
    imshow("draw_imag",draw_img);

    //result窗口以及显示结果
    secImg.convertTo(secImg,CV_8UC3);
    imshow("result",secImg);
//    imwrite(R"(C:\Users\Administrator\Desktop\card_black.png)",secImg);
}
