#include "TrackerDevice.h"
TrackerDevice::TrackerDevice(BaseDevice* device){
		Log::i( TAG, "Create...");
		this->mDevice = device;
		this->init();
	}

TrackerDevice::~TrackerDevice(){ 
	Log::i( TAG, "Destory...");
	this->mDevice = 0;
}
	
void TrackerDevice::init(){
	Log::i( TAG, "init...");
	this->mUserTracker = new nite::UserTracker();
	this->mUserTracker->create(this->mDevice);
	this->mUserTracker->setSkeletonSmoothingFactor(0.7f);
	this->mTrackerListener = new TrackerListener(this);
	this->mUserTracker->addNewFrameListener(this->mTrackerListener);
}

void TrackerDevice::shutdown(){
	this->mUserTracker->removeNewFrameListener(this->mTrackerListener);
	delete(this->mTrackerListener);
	this->mUserTracker->destroy();
	delete(this->mUserTracker);
	Log::i( TAG, "shutdown...");
}
