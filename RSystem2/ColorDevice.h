#ifndef _H_COLORDEVICE_
#define _H_COLORDEVICE_
#include <OpenNI.h>
#include "Log.h"
#include "BaseDevice.h"
#include "ColorStreamListener.h"

#define TAG "ColorDevice"

class ColorDevice {
private:
	openni::Device		*mDevice;
	openni::VideoStream	*mColorStream;
	ColorStreamListener	*mColorStreamListener;
public:
	ColorDevice(openni::Device*);
	~ColorDevice();
	void init();
	void shutdown();
};
#endif