/*
 * MLoadingLayer.h
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#ifndef MLOADINGLAYER_H_
#define MLOADINGLAYER_H_

#include "MBaseLayer.h"

class MLoadingLayer: public MBaseLayer {
public:
	MLoadingLayer();
	virtual ~MLoadingLayer();
	CREATE_FUNC(MLoadingLayer);
	bool init();

	void loadCallBack(CCObject* pObj);

	void showProgressBar();

	void goWelcomeLayer();

private:
	int loadingNum;
	int totalNum;
};

#endif /* MLOADINGLAYER_H_ */
