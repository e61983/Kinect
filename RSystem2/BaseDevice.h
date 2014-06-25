#ifndef _H_BASEDEVICE_
#define _H_BASEDEVICE_

#include <iostream>
#include <OpenNI.h>
#include <NiTE.h>
#include "Log.h"
#include "ColorDevice.h"
#include "DepthDevice.h"
#include "TrackerDevice.h"

#define TAG "BaseDevice"

/* �ѨMVS2010 ERROR C4430�����D */
class TrackerDevice;
class DepthDevice;
class ColorDevice;

class BaseDevice : virtual public openni::Device{

private:
	openni::Status	initNI();
	nite::Status	initNITE();
	void			shutdownNI();
	void			shutdownNITE();
	ColorDevice		*mColorDevice;
	DepthDevice		*mDepthDevice;
	TrackerDevice	*mTrackerDevice;
public:
					BaseDevice(void);
					~BaseDevice(void);
	bool			init();
	void			shutdown();
};
#endif /* _H_BASEDEVICE_ */