#ifndef __UPGRADESYSTEM_LAYER_H__
#define __UPGRADESYSTEM_LAYER_H__
#include "BaseLayer.h"
class UpgradeSystemLayer:public BaseLayer{
public:
	static cocos2d::CCScene* scene();
	virtual bool init();
	CREATE_FUNC(UpgradeSystemLayer);
private:
	// s���ý���
	bool setUpdateView();
	void publicClickCallBack(cocos2d::CCObject* pSend); // ͨ�ô����ص��¼�
	void updateClickCallBack(cocos2d::CCObject* pSend); // ������ť�ص��¼�
	void coniteClickCallBack(cocos2d::CCObject* pSend); // ������Ϸ��ť�ص��¼�
	void initDefner(int selectId);// ��ʼ����ʾ��ǩ������
	int  selectId;// ��ѡ�еĵ�ǰ�İ�ť��ID ֻҪֱͨ�õĶ���
};
#endif