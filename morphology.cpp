//
// Created by QYF on 2019/3/15.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main(int args,char** argv) {
    Mat src,dst;
    src = imread(R"(E:\��Ƭ\ͷ��.jpg)");
    assert(!src.empty());

    imshow("input",src);
    
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));
    //������
//    morphologyEx(src,dst,MORPH_OPEN,kernel);
    //�ղ���
//    morphologyEx(src,dst,MORPH_CLOSE,kernel);
    //��̬ѧ�ݶ�(�����ڲ��ݶȣ�ԭͼ-��ʴ��,�����ݶȣ�x��y�����Ͻ����ݶȼ���ó����ݶȣ�)
//    morphologyEx(src,dst,MORPH_GRADIENT,kernel);
    //��ñ
//    morphologyEx(src,dst,MORPH_TOPHAT,kernel);
    //��ñ
    morphologyEx(src,dst,MORPH_BLACKHAT,kernel);
    imshow("output",dst);
    
    waitKey(0);
    destroyAllWindows();
    return 0;
}