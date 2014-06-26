#include "ColorStreamListener.h"
ColorStreamListener::ColorStreamListener( ColorDevice* device ){
	Log::i( TAG, "Create...");
	this->colorMat = 0;
	this->mColorDevice = device;
}/* End of Constructor */

ColorStreamListener::~ColorStreamListener(){
	Log::i( TAG, "Destory...");
	this->colorMat = 0;
	this->mColorDevice = 0;
}/* End of Destructor */

void ColorStreamListener::onNewFrame(openni::VideoStream& steam){
	//Log::i( TAG, "onNewFrame");
	steam.readFrame(&(this->Frame));
		if (Frame.isValid()){
			if ( openni::SENSOR_COLOR == Frame.getSensorType() ){
				//cv::Mat mColorMat_BGR;
				this->colorMat = new cv::Mat(Frame.getHeight(),Frame.getWidth(),CV_8UC3,(void*)Frame.getData());
				//cv::cvtColor(mColorMat,mColorMat_BGR,CV_RGB2BGR);
			}/* End of if */
		}/* End of if */
}/* End of onNewFrame */