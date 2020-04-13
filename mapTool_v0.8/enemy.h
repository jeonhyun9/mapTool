#pragma once
#include "gameNode.h"

struct sEnemy
{
	float x, y;
	RECT rc;

};


class enemy : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

};

