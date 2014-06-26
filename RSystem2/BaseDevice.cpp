#include "BaseDevice.h"
using namespace std;
BaseDevice::BaseDevice(void) : openni::Device() {
	Log::i( TAG, "Create...");
	mColorDevice = 0;
	mDepthDevice = 0;
	mTrackerDevice = 0;
	ColorMat = 0;
	DepthMat = 0;
	userdata = 0;
	this->init();
}

BaseDevice::~BaseDevice(void){
	this->shutdown();
	Log::i( TAG, "Destory...");
}

openni::Status	
BaseDevice::initNI(){
	openni::Status mStatus;
	Log::i( TAG, "initNI...");
	openni::OpenNI::initialize();
	mStatus = this->open(openni::ANY_DEVICE);
	if ( mStatus != openni::STATUS_OK) {
		return mStatus;
	}
	this->setDepthColorSyncEnabled(true);
	this->setImageRegistrationMode(openni::IMAGE_REGISTRATION_DEPTH_TO_COLOR );

	this->mColorDevice = new ColorDevice(this);
	this->mDepthDevice = new DepthDevice(this);

	return mStatus;
}

nite::Status	
BaseDevice::initNITE(){
	nite::Status mStatus;
	Log::i( TAG, "initNITE...");
	mStatus = nite::NiTE::initialize();
	if( mStatus != nite::STATUS_OK )
		return mStatus;
	mTrackerDevice = new TrackerDevice(this);
	return mStatus;
}

bool			
BaseDevice::init(){
	Log::i( TAG, "Device init...");
	if ( initNI() != openni::STATUS_OK ){
		return false;
	}
	if ( initNITE() != nite::STATUS_OK ){
		return false;
	}
	return true;
}

void
BaseDevice::shutdown(){
	this->shutdownNITE();
	this->shutdownNI();
	Log::i( TAG, "Device shutdown...");
}

void	
BaseDevice::shutdownNITE(){
	this->mTrackerDevice->shutdown();
	nite::NiTE::shutdown();
	Log::i( TAG, "shutdownNITE...");
}

void	
BaseDevice::shutdownNI(){
	
	this->mDepthDevice->shutdown();
	delete(this->mDepthDevice);
	this->mColorDevice->shutdown();
	delete(this->mColorDevice);
	this->close();
	openni::OpenNI::shutdown();
	Log::i( TAG, "shutdownNI...");
}