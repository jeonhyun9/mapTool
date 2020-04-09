#pragma once
#include "gameNode.h"

struct tagboss
{
	float x, y;
	float speed;
	
};

class enemy : public gameNode
{
private:
	tagboss sBoss;



public:
	HRESULT init();
	void release();
	void update();
	void render();

	enemy() {}
	~enemy() {}


};

