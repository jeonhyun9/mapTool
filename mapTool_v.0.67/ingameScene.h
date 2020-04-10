#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemy.h"

class ingameScene : public gameNode
{
private:
	player* ptPlayer;
	enemy* ptEnemy;


public:
	HRESULT init();
	void release();
	void update();
	void render();

	ingameScene() {}
	~ingameScene() {}
};

