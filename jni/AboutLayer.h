/*
 * AboutLayer.h
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#ifndef ABOUTLAYER_H_
#define ABOUTLAYER_H_

#include "MBaseLayer.h"

class AboutLayer: public MBaseLayer {
public:
	AboutLayer();
	virtual ~AboutLayer();
	bool init();
	CREATE_FUNC(AboutLayer);
	void menuCallBack(CCObject* pObj);
};

#endif /* ABOUTLAYER_H_ */
