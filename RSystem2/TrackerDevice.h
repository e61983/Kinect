#ifndef _H_TRACKERDEVICE_
#define _H_TRACKERDEVICE_
#include <OpenNI.h>
#include "BaseDevice.h"
#include "TrackerListener.h"

#define TAG	"TrackerDevice"

class TrackerDevice{
private:
	openni::Device		*mDevice;
	nite::UserTracker	*mUserTracker;		
	TrackerListener		*mTrackerListener;
public:
	TrackerDevice(openni::Device*);
	~TrackerDevice();
	void init();
	void shutdown();
};
#endif