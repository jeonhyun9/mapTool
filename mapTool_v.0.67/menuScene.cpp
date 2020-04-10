#include "stdafx.h"
#include "menuScene.h"

HRESULT menuScene::init()
{
	menuBgImg = IMAGEMANAGER->findImage("�޴���׶���");
	buttonPlayImg = IMAGEMANAGER->findImage("�÷��̹�ư");
	buttonPlayOnImg = IMAGEMANAGER->findImage("�÷��̿¹�ư");
	buttonMapToolImg = IMAGEMANAGER->findImage("������ư");
	buttonMapToolOnImg = IMAGEMANAGER->findImage("�����¹�ư");
	buttonQuitImg = IMAGEMANAGER->findImage("�������ư");
	buttonQuitOnImg = IMAGEMANAGER->findImage("������¹�ư");

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
			//�ΰ��Ӿ���ȯ �������
			SCENEMANAGER->loadScene("�ΰ���");
		}
		if (PtInRect(&rcMapTool, _ptMouse))
		{
			SCENEMANAGER->loadScene("����");
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
