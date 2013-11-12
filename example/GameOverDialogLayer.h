#ifndef __GAMEOVERDIALOG_LAYER_H__
#define __GAMEOVERDIALOG_LAYER_H__
#include "BaseLayer.h"
class GameOverDialogLayer : public BaseLayer
{
public:
	GameOverDialogLayer();
	~GameOverDialogLayer();    
	virtual bool init();
	// ��ʼ���Ի�������
	bool setUpdateView();    
	CREATE_FUNC(GameOverDialogLayer);    
	void onEnter();
	void onExit();    
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};
#endif