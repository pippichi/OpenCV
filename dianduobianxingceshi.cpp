//
// Created by QYF on 2019/3/17.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



int main(int args,char** argv){
    Mat src,src_gray,dst;
    const int r = 100;
    src = Mat::zeros(r*4,r*4,CV_8UC1);
    vector<Point2f> vect(6);

    vect[0] = Point(3*r/2, static_cast<int>(1.34 * r));
    vect[1] = Point(1*r, 2*r);
    vect[2] = Point(3*r/2, static_cast<int>(2.866 * r));
    vect[3] = Point(5*r/2, static_cast<int>(2.866 * r));
    vect[4] = Point(3*r, 2*r);
    vect[5] = Point(5*r/2, static_cast<int>(1.34 * r));

    for(int i=0;i<vect.size();i++){
        line(src,vect[i],vect[(i+1)%6],Scalar(255),2,LINE_8);
    }

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    Mat csrc;
    src.copyTo(csrc);
    findContours(csrc,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
    Mat raw_dist = Mat::zeros(csrc.size(),CV_32FC1);
    for(int row=0;row<raw_dist.rows;row++){
        for(int col=0;col<raw_dist.cols;col++){
            //因为只有一个轮廓，因此用contours[0]
            double dist = pointPolygonTest(contours[0],Point(static_cast<int>(col), static_cast<int>(row)),true);
            raw_dist.at<float>(row,col) = static_cast<float>(dist);
        }
    }
    double minValue,maxValue;
    minMaxLoc(raw_dist,&minValue,&maxValue, nullptr, nullptr,Mat());
    Mat drawImg = Mat::zeros(raw_dist.size(),CV_8UC3);
    for(int row=0;row<drawImg.rows;row++){
        for(int col=0;col<drawImg.cols;col++){
            float dist = raw_dist.at<float>(row,col);
            if(dist>0){
                drawImg.at<Vec3b>(row,col)[0] = static_cast<uchar>(abs(1.0 - dist / maxValue) * 255);
            }else if(dist<0){
                drawImg.at<Vec3b>(row,col)[2] = static_cast<uchar>(abs(1.0 - dist / minValue) * 255);
            }else{
                drawImg.at<Vec3b>(row,col)[0] = static_cast<uchar>(255 - dist);
                drawImg.at<Vec3b>(row,col)[1] = static_cast<uchar>(255 - dist);
                drawImg.at<Vec3b>(row,col)[2] = static_cast<uchar>(255 - dist);
            }
        }
    }

    const char* output_win = "point poolygon test demo";
    const char input_win[] = "input image";

    imshow(input_win,src);
    imshow(output_win,drawImg);


    waitKey(0);
    destroyAllWindows();
    return 0;
}