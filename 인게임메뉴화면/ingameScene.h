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

	//타일 -이준
	tagTile sIngameTile[TILEX * TILEY];
	//배경화면 렉트 -이준
	RECT rcIngameBg;
	image* inGameBgImg;
	//로드용 이미지 - 이준
	image* inGameTerrainImg;
	image* inGameObjectImg;
	//윈사이즈 렉트 - 이준
	RECT rcIngameWins;

	RECT rc[100];
	tagEnemyData sEnemyData_ingame[100];

	//메뉴 렉트 - 이준 0413
	RECT rcMenuMain;
	float menuX, menuY;
	RECT rcMenuButtonRS;	//리썸
	RECT rcMenuButtonOP;	//옵션
	RECT rcMenuButtonEX;	//엑시트
	bool isMenu;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void load();

	ingameScene() {}
	~ingameScene() {}
};

