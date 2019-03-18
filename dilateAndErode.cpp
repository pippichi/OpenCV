//
// Created by QYF on 2019/3/14.
//
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src,dst;
int element_size = 3;
int max_size = 21;
char output[] = "output";
void CallBack_demo(int,void*);

int main(int args,char** argv) {
    src = imread(R"(E:\’’∆¨\1¥Á’’.jpg)");
    assert(!src.empty());

    imshow("input",src);

    CallBack_demo(0, nullptr);
    createTrackbar("Element Size: ",output,&element_size,max_size,CallBack_demo);

    waitKey(0);
    destroyAllWindows();
    return 0;
}

void CallBack_demo(int,void*){
    int s = element_size * 2 + 1;
    //–Œ◊¥£®MORPH_RECT/MORPH_CROSS/MORPH_ELLIPSE£©
    Mat structureElement = getStructuringElement(MORPH_RECT,Size(s,s),Point(-1,-1));
    //≈Ú’Õ
//    dilate(src,dst,structureElement,Point(-1,-1),1);
    //∏Ø ¥
    erode(src,dst,structureElement);
    imshow(output,dst);
}