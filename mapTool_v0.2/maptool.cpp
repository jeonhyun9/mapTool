#include "stdafx.h"
#include "maptool.h"

HRESULT maptool::init()
{
	//Ÿ�ϸ� �̹��� �ʱ�ȭ
	IMAGEMANAGER->addFrameImage("����Ÿ��1", "images/����Ÿ��1_����.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);


	//����Ÿ�� �ʱ�ȭ
	sCurrentTile.x = 4;
	sCurrentTile.y = 4;
	sToolBox.moveSpeed = 5;

	//Ÿ�� �¾�
	this->tileSetup();


	//���ڽ� + ������ + ��ư �¾�
	//this->toolBoxSetup();

	//�ʱ� ���� �� = ����
	ctrlSelect = CTRL_TERRAIN;

	return S_OK;
}

void maptool::release()
{
}

void maptool::update()
{
	this->toolBoxUpdate();
	//��Ŭ���� �ش� ��ġ�� ���õ� Ÿ�� �׸���
	if (INPUT->GetKey(VK_LBUTTON)) this->setMap();

	//��ư Ŭ�� �浹 ó��
	if (INPUT->GetKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&sToolBtn.rcSave, _ptMouse))
		{
			ctrlSelect = CTRL_SAVE;
			this->save();
		}
		if (PtInRect(&sToolBtn.rcLoad, _ptMouse))
		{
			ctrlSelect = CTRL_LOAD;
			this->load();
		}
		
		//���� ������
		//if (PtInRect(&rcTerrain, _ptMouse))
		//{
		//	ctrlSelect = CTRL_TERRAIN;
		//}
		//if (PtInRect(&_rcObject, _ptMouse))
		//{
		//	ctrlSelect = CTRL_OBJECT;
		//}
		//if (PtInRect(&_rcEraser, _ptMouse))
		//{
		//	ctrlSelect = CTRL_ERASER;
		//}
	}
}

void maptool::render()
{

	//�ΰ���ȭ�� ������ �׸���
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		IMAGEMANAGER->frameRender("����Ÿ��1", getMemDC(), sTile[i].rc.left, sTile[i].rc.top,
			sTile[i].terrainFrameX, sTile[i].terrainFrameY);
	}
	
	
	//F1 �Է½� �ΰ���ȭ�� ��Ʈ �����ֱ�
	if (INPUT->GetToggleKey(VK_F1))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			//FrameRect(getMemDC(), sTile[i].rc, RGB(255, 255, 0));
			//Rectangle(getMemDC(), sSampleTile[i].rc);
		}

	
	}
	
	//F2 �Է½� ���ڽ� + ������ + ��ư ��Ʈ �����ֱ�
	if (INPUT->GetToggleKey(VK_F2))
	{
		Rectangle(getMemDC(), sToolBox.rcBack);
		Rectangle(getMemDC(), sToolBox.rcPage);
		Rectangle(getMemDC(), sToolBtn.rcLoad);
		Rectangle(getMemDC(), sToolBtn.rcSave);
		Rectangle(getMemDC(), sToolBtn.rcReset);
		Rectangle(getMemDC(), sToolBtn.rcDelete);
		IMAGEMANAGER->render("����Ÿ��1",getMemDC(), sToolBox.rcBack.left, sToolBox.rcBack.top);
		for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
		{
			//Rectangle(getMemDC(), sSampleTile[i].rc);
			FrameRect(getMemDC(), sSampleTile[i].rc, RGB(255, 255, 0));
		}

		//���ڽ� ǥ�õǾ� ���� �� ȭ��ǥ �Է½� ���ڽ� �����¿� �̵�
		if (INPUT->GetKey(VK_LEFT))
		{
			sToolBox.x -= sToolBox.moveSpeed;
		}
		if (INPUT->GetKey(VK_RIGHT))
		{
			sToolBox.x += sToolBox.moveSpeed;
		}
		if (INPUT->GetKey(VK_UP))
		{
			sToolBox.y -= sToolBox.moveSpeed;
		}
		if (INPUT->GetKey(VK_DOWN))
		{
			sToolBox.y += sToolBox.moveSpeed;
		}
	}

}

void maptool::tileSetup()
{
	//���ڽ� �ʱ�ȭ
	sToolBox.toggle = false;
	sToolBox.x = 480;
	sToolBox.y = 670;
	sToolBox.width = 800;
	sToolBox.height = 350;

	//������ �ʱ�ȭ
	sToolBox.pageWidth = 480;
	sToolBox.pageHeight = 350;

	//����ư �ʱ�ȭ
	sToolBtn.width = 100;
	sToolBtn.height = 50;

	//���ڽ� ��� ��Ʈ ����
	sToolBox.rcBack = RectMakeCenter(sToolBox.x, sToolBox.y, sToolBox.width, sToolBox.height);

	//���ڽ� ������ ��Ʈ ����
	sToolBox.rcPage = RectMake(sToolBox.rcBack.left, sToolBox.rcBack.top, sToolBox.pageWidth, sToolBox.pageHeight);

	//���ڽ� ��ư ��Ʈ ����
	sToolBtn.rcDelete = RectMake(sToolBox.x + 100, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 250, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 100, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 250, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);


	//Ÿ�� ��Ʈ �ʱ�ȭ
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			sTile[i * TILEX + j].rc = RectMake(j * TILESIZE, i * TILESIZE, TILESIZE, TILESIZE);
		}
	}

	//������ ����Ÿ�� ��Ʈ �ʱ�ȭ
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			sSampleTile[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcPage.left + j * TILESIZE, sToolBox.rcPage.top + i * TILESIZE, TILESIZE, TILESIZE);
			sSampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			sSampleTile[i * SAMPLETILEX + j].terrainFrameY = i;
		}
	}

	//Ÿ���� �ʱ�ȭ�� 
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		sTile[i].terrainFrameX = 2; //���� Ÿ�� X��ǥ
		sTile[i].terrainFrameY = 0; //���� Ÿ�� Y��ǥ
		sTile[i].objFrameX = 0; //������Ʈ Ÿ�� X��ǥ
		sTile[i].objFrameY = 0; //������Ʈ Ÿ�� Y��ǥ
		sTile[i].terrain = terrainSelect(sTile[i].terrainFrameX, sTile[i].terrainFrameY); //�ش� X,Y ��ǥ �� ���� Ÿ�� ����
		sTile[i].obj = OBJ_NONE; //������Ʈ ���þ��� ����
	}
}

void maptool::setMap()
{
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
	{
		if (PtInRect(&sSampleTile[i].rc, _ptMouse))
		{
			sCurrentTile.x = sSampleTile[i].terrainFrameX;
			sCurrentTile.y = sSampleTile[i].terrainFrameY;
			break;
		}
	}

	//�ΰ���ȭ�� ��ƮƲ�� �浹�߳�?
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (PtInRect(&sTile[i].rc, _ptMouse))
		{
			//�����ư�� �����̳�?
			if (ctrlSelect == CTRL_TERRAIN)
			{
				sTile[i].terrainFrameX = sCurrentTile.x;
				sTile[i].terrainFrameY = sCurrentTile.y;
				sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
			}
			//�����ư�� ������Ʈ��?
			if (ctrlSelect == CTRL_OBJECT)
			{
				sTile[i].objFrameX = sCurrentTile.x;
				sTile[i].objFrameY = sCurrentTile.y;
				sTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);
			}
			//�����ư�� ���찳��?
			if (ctrlSelect == CTRL_ERASER)
			{
				sTile[i].objFrameX = 0;
				sTile[i].objFrameY = 0;
				sTile[i].obj = OBJ_NONE;
			}
		}
	}
}

void maptool::save()
{
	HANDLE file;
	DWORD write;

	file = CreateFile("save.map", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file, sTile, sizeof(tagTile) * TILEX * TILEY, &write, NULL);
	CloseHandle(file);
}

void maptool::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("save.map", GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, sTile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	CloseHandle(file);
}


void maptool::toolBoxUpdate()
{
	//���ڽ� ��� ��Ʈ ����
	sToolBox.rcBack = RectMakeCenter(sToolBox.x, sToolBox.y, sToolBox.width, sToolBox.height);

	//���ڽ� ������ ��Ʈ ����
	sToolBox.rcPage = RectMake(sToolBox.rcBack.left, sToolBox.rcBack.top, sToolBox.pageWidth, sToolBox.pageHeight);

	//���ڽ� ��ư ��Ʈ ����
	sToolBtn.rcDelete = RectMake(sToolBox.x + 100, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 250, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 100, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 250, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);

	//������ ����Ÿ�� ��Ʈ �ʱ�ȭ
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			sSampleTile[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcPage.left + j * TILESIZE, sToolBox.rcPage.top + i * TILESIZE, TILESIZE, TILESIZE);
			sSampleTile[i * SAMPLETILEX + j].terrainFrameX = j;
			sSampleTile[i * SAMPLETILEX + j].terrainFrameY = i;
		}
	}
}

TERRAIN maptool::terrainSelect(int frameX, int frameY)
{
	//�ø�Ʈ
	if (frameX == 1 && frameY == 0)
	{
		return TR_CEMENT;
	}
	//��
	if (frameX == 2 && frameY == 0)
	{
		return TR_GROUND;
	}
	//�ܵ�
	if (frameX == 3 && frameY == 0)
	{
		return TR_GRASS;
	}
	//��
	if (frameX == 4 && frameY == 0)
	{
		return TR_WATER;
	}

	//��Ÿ
	return TR_GROUND;
}

OBJECT maptool::objectSelect(int frameX, int frameY)
{
	return  OBJ_BLOCKS;
}

