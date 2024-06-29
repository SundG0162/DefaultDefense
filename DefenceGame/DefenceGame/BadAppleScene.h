#pragma once
#include"Scene.h"
#include<opencv2/opencv.hpp>
#include"Key.h"
class BadAppleScene : public Scene
{
public:
	BadAppleScene();
	~BadAppleScene();
public:
	void init() override;
	void update() override;
	void render() override;
private:
	KEY keyController();
private:
	float _framePerSecond = 31;
	int _curFrame = 0;
	int _width;
	int _height;
	cv::VideoCapture _cap;
	cv::Mat _frame, _grayFrame, _resizedFrame;
};

