#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
private:
	


public:
	HRESULT init();
	void release();
	void update();
	void render();

	enemy() {}
	~enemy() {}
};

