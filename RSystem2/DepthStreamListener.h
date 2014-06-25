#ifndef _H_DEPTH_STREAM_LISTENER_
#define _H_DEPTH_STREAM_LISTENER_
#include <OpenNI.h>
#include <opencv2\imgproc\imgproc.hpp>
#include "Log.h"

#define TAG	"DepthStreamListener"

class DepthStreamListener : virtual public openni::VideoStream::NewFrameListener{
private:
	openni::VideoFrameRef Frame;
	cv::Mat* depthMat;
public:
	DepthStreamListener();
	~DepthStreamListener();
	void onNewFrame(openni::VideoStream& );
};/* End of class ColorStreamListener */ 
#endif