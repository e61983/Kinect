#ifndef _H_COLOR_STREAM_LISTENER_
#define _H_COLOR_STREAM_LISTENER_
#include <OpenNI.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "Log.h"

#define TAG "ColorStreamListener"

class ColorStreamListener : virtual public openni::VideoStream::NewFrameListener{
private:
	openni::VideoFrameRef Frame;
	cv::Mat* colorMat;
public:
	ColorStreamListener();
	~ColorStreamListener();
	void onNewFrame(openni::VideoStream& );
};/* End of class ColorStreamListener */ 
#endif