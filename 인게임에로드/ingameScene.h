#pragma once
#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include "tileNode.h"

class ingameScene : public gameNode
{
private:
	player* ptPlayer;
	enemy* ptEnemy;

	//Ÿ�� -����
	tagTile sIngameTile[TILEX * TILEY];
	//���ȭ�� ��Ʈ -����
	RECT rcIngameBg;
	image* inGameBgImg;
	//�ε�� �̹��� - ����
	image* inGameTerrainImg;
	image* inGameObjectImg;
	//�������� ��Ʈ - ����
	RECT rcIngameWins;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void load();

	ingameScene() {}
	~ingameScene() {}
};

