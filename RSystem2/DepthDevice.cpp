#include "DepthDevice.h"

DepthDevice::DepthDevice(openni::Device* device){
	Log::i( TAG, "Create...");
	this->mDevice = device;
	this->init();
}

DepthDevice::~DepthDevice(){
	Log::i( TAG, "Destory...");
	this->mDevice = 0; 
}

void DepthDevice::init(){
	Log::i( TAG, "init...");
	openni::Status mStatus;
	this->mDepthStream = new openni::VideoStream();
	
	this->mDepthStream->create(*(this->mDevice),openni::SENSOR_DEPTH);
	openni::VideoMode mDepthMode;
	mDepthMode.setResolution(640,480);
	mDepthMode.setPixelFormat(openni::PIXEL_FORMAT_DEPTH_1_MM);
	mDepthMode.setFps(30);
	mStatus=mDepthStream->setVideoMode(mDepthMode);
	
	this->mDepthStreamListener = new DepthStreamListener();
	this->mDepthStream->addNewFrameListener(this->mDepthStreamListener);
	
	this->mDepthStream->start();
}

void DepthDevice::shutdown(){
	this->mDepthStream->removeNewFrameListener(this->mDepthStreamListener);
	this->mDepthStream->destroy();
	delete(this->mDepthStreamListener);
	delete(this->mDepthStream);
	Log::i( TAG, "shutdown...");
}