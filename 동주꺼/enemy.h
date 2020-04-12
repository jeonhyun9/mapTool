#pragma once
#include "gameNode.h"

struct sEnemy
{
	RECT rc;
	float x, y;
	bool fire;

};


class enemy : public gameNode
{
private:
	sEnemy mushroom;
	sEnemy boss;


public:
	HRESULT init();
	void release();
	void update();
	void render();

};

