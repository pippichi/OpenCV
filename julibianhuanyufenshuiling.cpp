//
// Created by QYF on 2019/3/18.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv){
    Mat src,l_src;
    src = imread(R"(C:\Users\Administrator\Desktop\card_black.png)");
    assert(!src.empty());
//    for(int row=0;row<src.rows;row++){
//        for(int col=0;col<src.cols;col++){
//            if(src.at<Vec3b>(row,col) == Vec3b(255,255,255)){
//                src.at<Vec3b>(row,col)[0] = 0;
//                src.at<Vec3b>(row,col)[1] = 0;
//                src.at<Vec3b>(row,col)[2] = 0;
//            }
//        }
//    }
    imshow("src",src);
    Mat laplanceImg;
    Mat kernel = (Mat_<float>(3,3)<<1,1,1,1,-8,1,1,1,1);
//    Laplacian(src,laplanceImg,-1,3,1,0);
    Mat sharpenSrc = src;
    filter2D(src,laplanceImg,CV_32F,kernel,Point(-1,-1),0,BORDER_DEFAULT);
    src.convertTo(sharpenSrc,CV_32F);
    Mat resultImg = sharpenSrc - laplanceImg;
    resultImg.convertTo(resultImg,CV_8UC3);
    laplanceImg.convertTo(laplanceImg,CV_8UC3);
    src.convertTo(src,CV_8UC3);
    imshow("resultImg",resultImg);

    //convert to binary
    Mat binaryImg;
    cvtColor(src,resultImg,COLOR_BGR2GRAY);
    threshold(resultImg,binaryImg,40,255,THRESH_OTSU | THRESH_BINARY);
    imshow("binary image",binaryImg);

    Mat distImg;
    //距离变换
    distanceTransform(binaryImg,distImg,DIST_L1,3,5);
    //防止像素负数
    convertScaleAbs(distImg,distImg);
    normalize(distImg,distImg,0,1,NORM_MINMAX);
    imshow("distance result",distImg*100);

    //binary again
    threshold(distImg,distImg,.4,1,THRESH_BINARY);
    Mat kernel1 = Mat::ones(3,3,CV_8UC1);
    erode(distImg,distImg,kernel1,Point(-1,-1));
    imshow("distance binary image",distImg*100);

    //markers
    Mat dist_8u;
    distImg.convertTo(dist_8u,CV_8U);
    vector<vector<Point>> contours;
    findContours(dist_8u,contours,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE,Point(0,0));

    //create markers
    Mat markers = Mat::zeros(src.size(),src.type());
    for(size_t i=0;i<contours.size();i++){
        //-1表示填充
        drawContours(markers, contours, static_cast<int>(i), Scalar::all(static_cast<int>(i) + 1),-1);
    }
    circle(markers,Point(5,5),3,Scalar(255,255,255),-1);
    imshow("my markers",markers*1000);

    //perform watershed
    watershed(src,markers);
    Mat mark = Mat::zeros(markers.size(),CV_8UC1);
    markers.convertTo(mark,CV_8UC1);
    bitwise_not(mark,mark,Mat());
    imshow("watershedImg",mark);

    //上色

    vector<Vec3b> colors;
    for(size_t i=0;i<contours.size();i++){
        int r = theRNG().uniform(0,255);
        int g = theRNG().uniform(0,255);
        int b = theRNG().uniform(0,255);
        colors.emplace_back((uchar)r,(uchar)g,(uchar)b);
    }

    Mat dst = Mat::zeros(markers.size(),CV_8UC3);
    for(int row=0;row<markers.rows;row++){
        for(int col=0;col<markers.cols;col++){
            int index = markers.at<int>(row,col);
            if(index>0&&index<= static_cast<int>(contours.size())){
                dst.at<Vec3b>(row,col) = colors[index-1];
            }else{
                dst.at<Vec3b>(row,col) = Vec3b(0,0,0);
            }
        }
    }
    imshow("Final Result",dst);

    waitKey(0);
    destroyAllWindows();
    return 0;

}

