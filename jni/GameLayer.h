/*
 * GameLayer.h
 *
 *  Created on: 2013-11-13
 *      Author: Administrator
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include "MBaseLayer.h"

class GameLayer: public MBaseLayer {
public:
	GameLayer();
	virtual ~GameLayer();

	bool init();
	CREATE_FUNC(GameLayer);
};

#endif /* GAMELAYER_H_ */
