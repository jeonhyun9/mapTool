#include "stdafx.h"
#include "menuScene.h"

HRESULT menuScene::init()
{
	menuBgImg = IMAGEMANAGER->findImage("메뉴백그라운드");
	buttonPlayImg = IMAGEMANAGER->findImage("플레이버튼");
	buttonPlayOnImg = IMAGEMANAGER->findImage("플레이온버튼");
	buttonMapToolImg = IMAGEMANAGER->findImage("맵툴버튼");
	buttonMapToolOnImg = IMAGEMANAGER->findImage("맵툴온버튼");
	buttonQuitImg = IMAGEMANAGER->findImage("나가기버튼");
	buttonQuitOnImg = IMAGEMANAGER->findImage("나가기온버튼");

	rcPlay = RectMake(900, 250, 278, 90);
	rcMapTool = RectMake(900, 400, 278, 90);
	rcQuit = RectMake(900, 550, 278, 90);

	playBtTouch = false;
	mapToolBtTouch = false;
	QuitBtTouch = false;

	return S_OK;
}

void menuScene::release()
{
}

void menuScene::update()
{
	if (PtInRect(&rcPlay, _ptMouse))
	{
		playBtTouch = true;
	}
	else
	{
		playBtTouch = false;
	}
	if (PtInRect(&rcMapTool, _ptMouse))
	{
		mapToolBtTouch = true;
	}
	else
	{
		mapToolBtTouch = false;
	}
	if (PtInRect(&rcQuit, _ptMouse))
	{
		QuitBtTouch = true;
	}
	else
	{
		QuitBtTouch = false;
	}

	if (INPUT->GetKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&rcPlay, _ptMouse))
		{
			//인게임씬전환 넣으면됨
			SCENEMANAGER->loadScene("인게임");
		}
		if (PtInRect(&rcMapTool, _ptMouse))
		{
			SCENEMANAGER->loadScene("맵툴");
		}
		if (PtInRect(&rcQuit, _ptMouse))
		{
			PostQuitMessage(0);
		}
	}
}

void menuScene::render()
{
	menuBgImg->render(getMemDC());

	if (playBtTouch == false)
	{
		buttonPlayImg->render(getMemDC(), rcPlay.left, rcPlay.top);
	}
	else
	{
		buttonPlayOnImg->render(getMemDC(), rcPlay.left, rcPlay.top);
	}

	if (mapToolBtTouch == false)
	{
		buttonMapToolImg->render(getMemDC(), rcMapTool.left, rcMapTool.top);
	}
	else
	{
		buttonMapToolOnImg->render(getMemDC(), rcMapTool.left, rcMapTool.top);
	}

	if (QuitBtTouch == false)
	{
		buttonQuitImg->render(getMemDC(), rcQuit.left, rcQuit.top);
	}
	else
	{
		buttonQuitOnImg->render(getMemDC(), rcQuit.left, rcQuit.top);
	}
}
