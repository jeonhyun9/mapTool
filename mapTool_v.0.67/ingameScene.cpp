#include "stdafx.h"
#include "ingameScene.h"

HRESULT ingameScene::init()
{
	ptPlayer = new player;
	ptPlayer->init();

	ptEnemy = new enemy;
	ptEnemy->init();

	return S_OK;
}

void ingameScene::release()
{
	ptPlayer->release();
	ptEnemy->release();
}

void ingameScene::update()
{
	ptPlayer->update();
	ptEnemy->update();
}

void ingameScene::render()
{
	ptPlayer->render();
	ptEnemy->render();
}
