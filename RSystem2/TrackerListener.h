#ifndef _H_TRACKERLISTERNER_
#define _H_TRACKERLISTERNER_
#include <NiTE.h>
#include <opencv2\highgui\highgui.hpp>
#include "Log.h"
#include "TrackerDevice.h"

#define TAG	"TrackerListener"
class	TrackerDevice;
class	nite::UserTrackerFrameRef;
class TrackerListener : virtual public nite::UserTracker::NewFrameListener {
private:
	TrackerDevice				*mDevice;
	nite::UserTrackerFrameRef	userTrackerFrameRef;
public:
	TrackerListener(TrackerDevice*);
	~TrackerListener();
	void onNewFrame(nite::UserTracker& userTracker);
}; 
#endif