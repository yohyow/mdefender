/*
 * MBaseLayer.h
 *
 *  Created on: 2013-11-12
 *      Author: Administrator
 */

#ifndef MBASELAYER_H_
#define MBASELAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class MBaseLayer: public cocos2d::CCLayer {
public:
	MBaseLayer();
	virtual ~MBaseLayer();
	static CCScene* createScene(CCLayer* pCCLayer);
	virtual bool init();
	CREATE_FUNC(MBaseLayer);
	CCSize getWinSize();//得到当前可视窗口大小
	CCPoint getWinSizeWithOrign();//得到当前可视窗口的起始点
	CCPoint getWinCenterPoint();//得到屏幕正中间的点
	CCPoint converToSpritRel(float x, float y);//转换屏幕位置为可视窗口位置
};

#endif /* MBASELAYER_H_ */
