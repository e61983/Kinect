#include "DepthStreamListener.h"

DepthStreamListener::DepthStreamListener(DepthDevice* device){
	Log::i( TAG, "Create...");
	this->depthMat = 0;
	this->mDepthDevice = device;
}/* End of Constructor */

DepthStreamListener::~DepthStreamListener(){
	Log::i( TAG, "Destory...");
	this->depthMat = 0;
}/* End of Destructor */

void DepthStreamListener::onNewFrame(openni::VideoStream& steam){
	//Log::i( TAG, "onNewFrame");
	steam.readFrame(&(this->Frame));
		if (Frame.isValid()){
			if ( openni::SENSOR_DEPTH == Frame.getSensorType()){
				this->depthMat = new cv::Mat(Frame.getHeight(),Frame.getWidth(),CV_16UC1,(void*)Frame.getData());
			}/* End of if */
		}/* End of if */
}/* End of onNewFrame */
