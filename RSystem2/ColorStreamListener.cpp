#include "ColorStreamListener.h"
ColorStreamListener::ColorStreamListener(){
	Log::i( TAG, "Create...");
	this->colorMat = 0;
}/* End of Constructor */

ColorStreamListener::~ColorStreamListener(){
	Log::i( TAG, "Destory...");
	if ( 0 != this->colorMat ){
		delete(this->colorMat);
	}/* End of if */
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