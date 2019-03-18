//
// Created by QYF on 2019/3/16.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


Mat src,dst,output;
int t1_value = 50;
int max_value = 255;
const char* OUTPUT_TITLE = "Canny Result";
void Canny_Demo(int,void*);
int main(int args,char** argv) {
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");
    assert(!src.empty());

    cvtColor(src,dst,COLOR_BGR2GRAY);
    Canny_Demo(0,nullptr);
    createTrackbar("Threshold Value: ",OUTPUT_TITLE,&t1_value,max_value,Canny_Demo);


    waitKey(0);
    destroyAllWindows();
    return 0;
}
void Canny_Demo(int,void*){
    Mat edge_output;
    blur(dst,dst,Size(3,3),Point(-1,-1));
    Canny(dst,edge_output,t1_value,t1_value*2,3);
    imshow("canny",edge_output);
    output.create(src.size(),src.type());
    src.copyTo(output,edge_output);
    imshow(OUTPUT_TITLE,output);
}