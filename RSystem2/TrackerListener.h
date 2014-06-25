#ifndef _H_TRACKERLISTERNER_
#define _H_TRACKERLISTERNER_
#include <NiTE.h>
#include <opencv2\highgui\highgui.hpp>
#include "Log.h"

#define TAG	"TrackerListener"

class TrackerListener : virtual public nite::UserTracker::NewFrameListener {
private:
	 nite::UserTrackerFrameRef userTrackerFrameRef;
public:
	TrackerListener();
	~TrackerListener();
	void onNewFrame(nite::UserTracker& userTracker);
}; 
#endif