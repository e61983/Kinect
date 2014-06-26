#include "TrackerListener.h"
#include <iostream>

TrackerListener::TrackerListener( TrackerDevice *device ){
	Log::i( TAG, "Create...");
	mDevice = device;
}/* End of Constructor */

TrackerListener::~TrackerListener(){
	Log::i( TAG, "Destory...");
	mDevice = 0;
}/* End of Destructor */

void TrackerListener::onNewFrame(nite::UserTracker& userTracker){
	 nite::Status niteRc = userTracker.readFrame(&userTrackerFrameRef);
	 if (niteRc != nite::STATUS_OK){
		 Log::i(TAG,"Get next frame failed");
	}	
	const nite::Array<nite::UserData>& users = userTrackerFrameRef.getUsers();
	for ( int i = 0; i < users.getSize(); i++ ){
		const nite::UserData& user = users[i];
		
		if ( user.isNew() ){
			userTracker.startSkeletonTracking(user.getId());
			Log::i(TAG,"isNEW");
		}/* End of if */

		if (user.isVisible()){		
			Log::i(TAG,"isVisible");
			this->mDevice->setData(nite::UserData(user));
		}/* End of if  */
		if ( user.isLost() ){
			userTracker.stopSkeletonTracking(user.getId());
			Log::i(TAG,"isLost");
		}/* End of if */
	}/* End of for : i */
}/* End of TrackerListener::onNewFrame */