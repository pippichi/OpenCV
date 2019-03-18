//
// Created by QYF on 2019/3/13.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat bgImage;
const char*drawdemo_win = "draw shapes and text demo";
void MyLines();
void MyRectangle();
void MyEllipse();
void MyCircle();
void MyPolygon();
void RandomLineDemo();
int main(int args,char** argv){
    Mat src,dst;
    bgImage = imread(R"(C:\Users\Administrator\Desktop\test1.png)");
    if(!bgImage.data){
        cout << "cannot find the pic"<<endl;
        return -1;
    }

    //绘制图形
    MyLines();
    MyRectangle();
    MyEllipse();
    MyCircle();
    MyPolygon();

    //绘制文字
    putText(bgImage,"hello opencv",Point(300,300),FONT_HERSHEY_COMPLEX,1.0,Scalar(12,256,200),3,LINE_8);
    imshow(drawdemo_win,bgImage);

    //绘制随机线
    RandomLineDemo();

    waitKey(0);
    destroyAllWindows();
    return 0;
}

void MyLines(){
    Point p1 = Point(0,0);
    Point p2;
    p2.x = 300;
    p2.y = 300;
    Scalar color = Scalar(0,0,255);
    line(bgImage,p1,p2,color,1,LINE_AA);
}

void MyRectangle(){
    Rect rect = Rect(200,100,300,300);
    Scalar color = Scalar(0,0,255);
    rectangle(bgImage,rect,color,2,LINE_8);
}

void MyEllipse(){
    Scalar color = Scalar(0,255,0);
    ellipse(bgImage,Point(bgImage.cols/8,bgImage.rows/8),Size(bgImage.cols/4,bgImage.rows/8),60,0,270,color,2,LINE_8);
}

void MyCircle(){
    Scalar color = Scalar(255,255,0);
    circle(bgImage,Point(bgImage.cols/4,bgImage.rows/4),150,color,2,LINE_8);
}

void MyPolygon(){
    Point pts[1][5];
    pts[0][0] = Point(100,100);
    pts[0][1] = Point(100,200);
    pts[0][2] = Point(200,200);
    pts[0][3] = Point(200,100);
    pts[0][4] = Point(100,100);
    const Point* ppts[] = {pts[0]};
    int npt[] = {5};
    Scalar color = Scalar(255,12,0);

    fillPoly(bgImage,ppts,npt,1,color,LINE_8);

}

void RandomLineDemo(){
    //随机数种子
    RNG rng(12345);

    Point pt1;
    Point pt2;
    Mat bg = Mat::zeros(bgImage.size(),bgImage.type());

    //生成随机数 rng.uniform();
    for(int i=0;i<100000;i++) {
        pt1.x = rng.uniform(0, bgImage.cols);
        pt2.x = rng.uniform(0, bgImage.cols);
        pt1.y = rng.uniform(0, bgImage.rows);
        pt2.y = rng.uniform(0, bgImage.rows);
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        if(waitKey(50)>0){
            break;
        }

        line(bg, pt1, pt2, color, 1, LINE_8);
        imshow("random_line",bg);
    }
}