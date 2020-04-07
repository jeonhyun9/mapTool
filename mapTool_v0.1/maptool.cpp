#include "stdafx.h"
#include "maptool.h"

HRESULT maptool::init()
{
	//타일 셋업
	this->tileSetup();
	//툴박스 + 페이지 + 버튼 셋업
	this->toolBoxSetup();

	return S_OK;
}

void maptool::release()
{
}

void maptool::update()
{
}

void maptool::render()
{
	//F1 입력시 인게임화면 렉트 보여주기
	if (INPUT->GetToggleKey(VK_F1))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			Rectangle(getMemDC(), sTile[i].rc);
		}
	}

	//F2 입력시 툴박스 + 페이지 + 버튼 렉트 보여주기
	if (INPUT->GetToggleKey(VK_F2))
	{
		Rectangle(getMemDC(), sToolBox.rc);
		Rectangle(getMemDC(), sToolBox.rcPage);
		Rectangle(getMemDC(), sToolBtn.rcLoad);
		Rectangle(getMemDC(), sToolBtn.rcSave);
		Rectangle(getMemDC(), sToolBtn.rcReset);
		Rectangle(getMemDC(), sToolBtn.rcDelete);
	}
}

void maptool::tileSetup()
{
	//타일 렉트 초기화
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			sTile[i * TILEX + j].rc = RectMake(j * TILESIZE, i * TILESIZE, TILESIZE, TILESIZE);
		}
	}
}

void maptool::toolBoxSetup()
{
	//툴박스 초기화
	sToolBox.x = 480;
	sToolBox.y = 670;
	sToolBox.width = 700;
	sToolBox.height = 400;

	//페이지 초기화
	sToolBox.pageWidth = 350;
	sToolBox.pageHeight = 400;

	//툴버튼 초기화
	sToolBtn.width = 100;
	sToolBtn.height = 50;

	//툴박스 렉트 생성
	sToolBox.rc = RectMakeCenter(sToolBox.x, sToolBox.y, sToolBox.width, sToolBox.height);

	//툴박스 페이지 생성
	sToolBox.rcPage = RectMake(sToolBox.rc.left, sToolBox.rc.top, sToolBox.pageWidth, sToolBox.pageHeight);

	//툴박스 버튼 렉트 생성
	sToolBtn.rcDelete = RectMake(sToolBox.x + 50, sToolBox.y - 100, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 200, sToolBox.y - 180, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 200, sToolBox.y - 100, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 50, sToolBox.y - 180, sToolBtn.width, sToolBtn.height);
}

