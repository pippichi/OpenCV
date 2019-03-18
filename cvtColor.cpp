#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int args,char** argv) {
    Mat src,dst;
    src = imread(R"(C:\Users\Administrator\Desktop\1.jpg)");//ºó×º¿É¼ÓIMREAD_UNCHANGED,IMREAD_GRAYSCALE,IMREAD_COLOR
    //namedWindow("input_image", WINDOW_AUTOSIZE);
    imshow("input", src);
    cvtColor(src,dst,COLOR_BGR2GRAY);
    imshow("output", dst);
    waitKey(0);
    destroyAllWindows();
    return 0;
}