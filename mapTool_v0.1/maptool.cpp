#include "stdafx.h"
#include "maptool.h"

HRESULT maptool::init()
{
	//Ÿ�� �¾�
	this->tileSetup();
	//���ڽ� + ������ + ��ư �¾�
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
	//F1 �Է½� �ΰ���ȭ�� ��Ʈ �����ֱ�
	if (INPUT->GetToggleKey(VK_F1))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			Rectangle(getMemDC(), sTile[i].rc);
		}
	}

	//F2 �Է½� ���ڽ� + ������ + ��ư ��Ʈ �����ֱ�
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
	//Ÿ�� ��Ʈ �ʱ�ȭ
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
	//���ڽ� �ʱ�ȭ
	sToolBox.x = 480;
	sToolBox.y = 670;
	sToolBox.width = 700;
	sToolBox.height = 400;

	//������ �ʱ�ȭ
	sToolBox.pageWidth = 350;
	sToolBox.pageHeight = 400;

	//����ư �ʱ�ȭ
	sToolBtn.width = 100;
	sToolBtn.height = 50;

	//���ڽ� ��Ʈ ����
	sToolBox.rc = RectMakeCenter(sToolBox.x, sToolBox.y, sToolBox.width, sToolBox.height);

	//���ڽ� ������ ����
	sToolBox.rcPage = RectMake(sToolBox.rc.left, sToolBox.rc.top, sToolBox.pageWidth, sToolBox.pageHeight);

	//���ڽ� ��ư ��Ʈ ����
	sToolBtn.rcDelete = RectMake(sToolBox.x + 50, sToolBox.y - 100, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 200, sToolBox.y - 180, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 200, sToolBox.y - 100, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 50, sToolBox.y - 180, sToolBtn.width, sToolBtn.height);
}

