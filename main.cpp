#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void averageFilter(Mat& src, Mat& result, int besarKernel);
Mat rgb2gray(Mat& src);

int main(int argc, char *argv[])
{
    Mat src = imread("D:\\Project\\C++\\CitraDigital\\lena.jpg");

    src = rgb2gray(src);

    Mat mean_filter;

    averageFilter(src, mean_filter, 7);

    namedWindow("asli");
    imshow("asli", src);

    namedWindow("mean");
    imshow("mean", mean_filter);

    waitKey(0);

}

void averageFilter(Mat& src, Mat& result, int besarKernel)
{

    int filterOffset = besarKernel / 2;

    result = Mat::zeros(src.rows - filterOffset, src.cols - filterOffset, src.type());
    int x = 0, y = 0;
    double sumKeabuan;

    for(int ysrc = filterOffset; ysrc < src.rows - filterOffset; ++ysrc){
        x = 0;
        for(int xsrc = filterOffset; xsrc < src.cols - filterOffset; ++xsrc){

            sumKeabuan = 0;
            // matrix kernel = besarKernel x besarKernel mempunyai nilai 1
            for(int ykernel = -filterOffset; ykernel <= filterOffset; ++ykernel){
                for(int xkernel = -filterOffset; xkernel <= filterOffset; ++xkernel){

                    sumKeabuan += src.at<uchar>(ysrc + ykernel, xsrc + xkernel);
                }
            }

            result.at<uchar>(y, x) = sumKeabuan / ( besarKernel * besarKernel);
            ++x;
        }
        ++y;
    }
}

Mat rgb2gray(Mat& src)
{
    CV_Assert(src.depth() != sizeof(uchar)); //harus 8 bit

    Mat mc1(src.rows, src.cols, CV_8UC1); //buat matrik 1 chanel
    uchar data;

    if(src.channels() == 3){
        Mat_<Vec3b> _I = src;

        for( int i = 0; i < src.rows; ++i)
            for( int j = 0; j < src.cols; ++j )
            {
                data = (uchar)(_I(i,j)[0] * 0.0722 + _I(i,j)[1] * 0.7152 + _I(i,j)[2] * 0.2126);

                mc1.at<uchar>(i,j) = data;

            }

        src = _I;
        return mc1;

    }else{

        return src;
    }

}
