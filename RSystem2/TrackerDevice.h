#ifndef _H_TRACKERDEVICE_
#define _H_TRACKERDEVICE_
#include <OpenNI.h>
#include "BaseDevice.h"
#include "TrackerListener.h"

#define TAG	"TrackerDevice"
class	BaseDevice;
class	nite::UserTracker;
class	TrackerListener;
class TrackerDevice{
private:
	BaseDevice			*mDevice;
	nite::UserTracker	*mUserTracker;		
	TrackerListener		*mTrackerListener;
public:
	TrackerDevice(BaseDevice*);
	~TrackerDevice();
	void init();
	void shutdown();
};
#endif