#ifndef _H_COLORDEVICE_
#define _H_COLORDEVICE_
#include <OpenNI.h>
#include <opencv2\highgui\highgui.hpp>
#include "Log.h"
#include "BaseDevice.h"
#include "ColorStreamListener.h"

#define TAG "ColorDevice"
class BaseDevice;
class openni::VideoStream;
class ColorStreamListener;
class ColorDevice {
private:
	BaseDevice			*mDevice;
	openni::VideoStream	*mColorStream;
	ColorStreamListener	*mColorStreamListener;
public:
	ColorDevice( BaseDevice* );
	~ColorDevice();
	void init();
	void shutdown();
};
#endif