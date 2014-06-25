#ifndef _H_DEPTHDEVICE_
#define _H_DEPTHDEVICE_
#include <OpenNI.h>
#include "Log.h"
#include "BaseDevice.h"
#include "DepthStreamListener.h"

#define TAG "DepthDevice"

class DepthDevice{
private:
	openni::Device		*mDevice;
	openni::VideoStream	*mDepthStream;
	DepthStreamListener	*mDepthStreamListener;
public:
	DepthDevice(openni::Device*);
	~DepthDevice();
	void init();
	void shutdown();
};
#endif