#ifndef _H_DEPTH_STREAM_LISTENER_
#define _H_DEPTH_STREAM_LISTENER_
#include <OpenNI.h>
#include <opencv2\imgproc\imgproc.hpp>
#include "Log.h"
#include "DepthDevice.h"

#define TAG	"DepthStreamListener"
class DepthDevice;
class DepthStreamListener : virtual public openni::VideoStream::NewFrameListener{
private:
	openni::VideoFrameRef	Frame;
	cv::Mat					*depthMat;
	DepthDevice				*mDepthDevice;
public:
	DepthStreamListener( DepthDevice* );
	~DepthStreamListener();
	void onNewFrame(openni::VideoStream& );
};/* End of class ColorStreamListener */ 
#endif