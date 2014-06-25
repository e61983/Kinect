#include "ColorDevice.h"
	ColorDevice::ColorDevice(openni::Device* device){
		Log::i( TAG, "Create...");
		this->mDevice = device; 
		this->init();
	}

	ColorDevice::~ColorDevice(){ 
		Log::i( TAG, "Destory...");
		this->mDevice = 0;
	}
	
	void ColorDevice::init(){
	openni::Status mStatus;
	Log::i( TAG, "init...");
	this->mColorStream = new openni::VideoStream();
	
	this->mColorStream->create(*(this->mDevice),openni::SENSOR_COLOR);
	openni::VideoMode mColorMode;
	mColorMode.setResolution(640,480);
	mColorMode.setPixelFormat(openni::PIXEL_FORMAT_RGB888);
	mColorMode.setFps(30);
	mStatus=this->mColorStream->setVideoMode(mColorMode);
	
	this->mColorStreamListener = new ColorStreamListener();
	this->mColorStream->addNewFrameListener(this->mColorStreamListener);
	
	this->mColorStream->start();
	}

	void ColorDevice::shutdown(){
		this->mColorStream->removeNewFrameListener(this->mColorStreamListener);
		this->mColorStream->destroy();
		delete(this->mColorStreamListener);
		delete(this->mColorStream);
		Log::i( TAG, "shutdown...");
	}
