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
	CCSize getWinSize();//�õ���ǰ���Ӵ��ڴ�С
	CCPoint getWinSizeWithOrign();//�õ���ǰ���Ӵ��ڵ���ʼ��
	CCPoint getWinCenterPoint();//�õ���Ļ���м�ĵ�
	CCPoint converToSpritRel(float x, float y);//ת����Ļλ��Ϊ���Ӵ���λ��
};

#endif /* MBASELAYER_H_ */
