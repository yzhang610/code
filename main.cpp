#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\core\core.hpp>
#include<iostream>

#define threshold_diff1 10;
#define threshold_diff2 10;

using namespace std;
using namespace cv;

int main()
{
	Mat img_src1, img_src2, img_src3;
	Mat img_dst, gray1, gray2, gray3;
	Mat gray_diff1, gray_diff2;
	Mat gray;
	int i, j;
	int scale = 4;
	int width, height;
	bool pause = false;
	
	VideoCapture video_file("test.mp4");
	namedWindow("foreground", 0);
	for(; ;)
	{
		if(!false)
		{
			video_file >> img_src1;
			width = img_src1.cols / scale;
			height = img_src1.rows / scale;
			Size sz(width, height);
			gray_diff1 = Mat::zeros(sz, CV_8UC1);
			gray_diff2 = Mat::zeros(sz, CV_8UC1);

			waitKey(5);
			video_file >> img_src1;
			resize(img_src1, img_src1, sz);
			cvtColor(img_src1, gray1, CV_BGR2GRAY);
			

			waitKey(5);
			video_file >> img_src2;
			resize(img_src2, img_src2, sz);
			cvtColor(img_src2, gray2, CV_BGR2GRAY);
			waitKey(5);

			video_file >> img_src3;
			resize(img_src3, img_src3, sz);
			cvtColor(img_src3, gray3, CV_BGR2GRAY);

			subtract(gray2, gray1, gray_diff1);
			subtract(gray3, gray2, gray_diff2);

			for(i = 0; i < gray_diff1.rows; i++)
			{
				for(j = 0; j < gray_diff1.cols; j++)
				{
					if(abs(gray_diff1.at<unsigned char>(i, j)) >= 10)
						gray_diff1.at<unsigned char>(i, j) = 255;
					else
						gray_diff1.at<unsigned char>(i, j) = 0;
					if(abs(gray_diff2.at<unsigned char>(i, j)) >= 10)
						gray_diff2.at<unsigned char>(i, j) = 255;
					else
						gray_diff2.at<unsigned char>(i, j) = 0;
				}
			}
			imshow("两帧帧差法1",gray_diff1);
			imshow("两帧帧差法2",gray_diff2);
			bitwise_and(gray_diff1, gray_diff2, gray);
			imshow("foreground", gray);
		}
		char c = (char)waitKey(10);
		if(c == 27)
			break;
		if(c == ' ')
			pause = !pause;
	}
	return 0;
}