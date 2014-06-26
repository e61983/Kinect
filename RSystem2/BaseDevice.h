#ifndef _H_BASEDEVICE_
#define _H_BASEDEVICE_

#include <iostream>
#include <OpenNI.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <NiTE.h>
#include "Log.h"
#include "ColorDevice.h"
#include "DepthDevice.h"
#include "TrackerDevice.h"

#define TAG "BaseDevice"

/* 解決VS2010 ERROR C4430的問題 */
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
	cv::Mat			*ColorMat;
	cv::Mat			*DepthMat;
	nite::UserData	*Userdata;
public:
					BaseDevice(void);
					~BaseDevice(void);
	void			setColorData( cv::Mat & );
	cv::Mat*		getColorData(void);
	void			setDepthData( cv::Mat & );
	cv::Mat*		getDepthData(void);
	void			setTrackerData( nite::UserData & );
	nite::UserData*	getTrackerData(void);
	bool			init();
	void			shutdown();
};
#endif /* _H_BASEDEVICE_ */