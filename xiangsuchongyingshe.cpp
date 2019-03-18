//
// Created by QYF on 2019/3/16.
//
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,dst,map_x,map_y;
const char* OUTPUT_TITLE = "remap demo";
void update_map(int &index);
int main(int args,char** argv){
    int index;
    src = imread(R"(C:\Users\Administrator\Desktop\test1.png)");
    assert(!src.empty());
    imshow("input",src);

    map_x.create(src.size(),CV_32FC1);
    map_y.create(src.size(),CV_32FC1);

    int c = 0;
    while(true){
        c = waitKey(500);
        if((char)c==27){
            break;
        }
        index = (c % 4);
        update_map(index);
        //选择线性插入INTER_LINEAR
        remap(src,dst,map_x,map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,255,255));
        imshow("dst",dst);
    }
    destroyAllWindows();
    return 0;
}
void update_map(int &index){
    for(int row=0;row<src.rows;row++){
        for(int col=0;col<src.cols;col++){
            switch(index){
                case 0:
                    if(col>(src.cols*0.25)&&col<(src.cols*0.75)&&row>(src.rows*0.25)&&row<(src.rows*0.75)){
                        map_x.at<float>(row,col) = (float)(2 * (col - src.cols * 0.25));
                        map_y.at<float>(row,col) = (float)(2 * (row - src.rows * 0.25));
                    }else{
                        map_x.at<float>(row,col) = 0;
                        map_y.at<float>(row,col) = 0;
                    }
                    break;
                case 1:
                    map_x.at<float>(row,col) = (float)(src.cols - col - 1);
                    map_y.at<float>(row,col) = row;
                    break;
                case 2:
                    map_x.at<float>(row,col) = col;
                    map_y.at<float>(row,col) = (float)(src.rows - row - 1);
                    break;
                case 3:
                    map_x.at<float>(row,col) = (float)(src.cols - col - 1);
                    map_y.at<float>(row,col) = (float)(src.rows - row - 1);
                    break;
                default:
                    map_x.at<float>(row,col) = col;
                    map_y.at<float>(row,col) = row;
            }
        }
    }
}