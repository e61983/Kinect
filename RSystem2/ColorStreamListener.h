#ifndef _H_COLOR_STREAM_LISTENER_
#define _H_COLOR_STREAM_LISTENER_
#include <OpenNI.h>
#include <opencv2\imgproc\imgproc.hpp>
#include "Log.h"
#include "ColorDevice.h"


#define TAG "ColorStreamListener"
class ColorDevice;
class ColorStreamListener : virtual public openni::VideoStream::NewFrameListener{
private:
	openni::VideoFrameRef	Frame;
	cv::Mat					*colorMat;
	ColorDevice				*mColorDevice;
public:
	ColorStreamListener( ColorDevice* );
	~ColorStreamListener();
	void onNewFrame(openni::VideoStream& );
};/* End of class ColorStreamListener */ 
#endif