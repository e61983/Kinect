#ifndef _H_DEPTHDEVICE_
#define _H_DEPTHDEVICE_
#include <OpenNI.h>
#include "Log.h"
#include "BaseDevice.h"
#include "DepthStreamListener.h"

#define TAG "DepthDevice"
class BaseDevice;
class openni::VideoStream;
class DepthStreamListener;
class DepthDevice{
private:
	BaseDevice			*mDevice;
	openni::VideoStream	*mDepthStream;
	DepthStreamListener	*mDepthStreamListener;
public:
	DepthDevice(BaseDevice*);
	~DepthDevice();
	void init();
	void shutdown();
};
#endif