#include "stdafx.h"
#include "ingameScene.h"

HRESULT ingameScene::init()
{
	ptPlayer = new player;
	ptPlayer->init();

	ptEnemy = new enemy;
	ptEnemy->init();

	//��׶��� ��Ʈ - ����
	rcIngameBg = RectMake(0, 0, 6000, 960);
	inGameBgImg = IMAGEMANAGER->findImage("��׶���");

	//�ΰ��� �ε� �̹��� - ����
	inGameTerrainImg = IMAGEMANAGER->findImage("����Ÿ��_����");
	inGameObjectImg = IMAGEMANAGER->findImage("������ƮŸ��_����");

	//�������� ��Ʈ - ����
	rcIngameWins = RectMake(0, 0, WINSIZEX, WINSIZEY);

	//�޴����� ���� - ���� 0413
	menuX = WINSIZEX / 2;
	menuY = -256;
	//�޴� ��Ʈ �ʱ�ȭ - ���� 0413
	rcMenuMain = RectMakeCenter(WINSIZEX / 2, -270, 594, 540);
	isMenu = false;
	isTouch_RS = false;
	isTouch_EX = false;

	return S_OK;
}

void ingameScene::release()
{
	ptPlayer->release();
	ptEnemy->release();
}

void ingameScene::update()
{
	
	rcMenuButtonRS = RectMake(rcMenuMain.left + 240, rcMenuMain.top + 220, 170, 62);
	rcMenuButtonEX = RectMake(rcMenuMain.left + 240, rcMenuMain.top + 320, 170, 62);

	//�Լ� �߰� - ����
	this->load();

	//Ÿ�� ��Ʈ �ʱ�ȭ - ����
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			sIngameTile[i * TILEX + j].rc = RectMake(rcIngameBg.left + j * TILESIZE, rcIngameBg.top + i * TILESIZE, TILESIZE, TILESIZE);
		}
	}

	//ESC ��ư �߰� - ����0413
	if (INPUT->GetKeyDown(VK_F2))
	{
		isMenu = true;
	}
	if (isMenu)
	{
		rcMenuMain.bottom += 10;
		rcMenuMain.top += 10;
		if (rcMenuMain.top >= WINSIZEY / 2 - 270)
		{
			rcMenuMain.top = WINSIZEY / 2 - 270;
			rcMenuMain.bottom = rcMenuMain.top + 540;
		}

		if (PtInRect(&rcMenuButtonRS, _ptMouse))
		{
			isTouch_RS = true;
			if (INPUT->GetKeyDown(VK_LBUTTON))
			{
				isMenu = false;
			}
		}
		else
		{
			isTouch_RS = false;
		}

		if (PtInRect(&rcMenuButtonEX, _ptMouse))
		{
			isTouch_EX = true;
			if (INPUT->GetKeyDown(VK_LBUTTON))
			{
				SCENEMANAGER->loadScene("�޴�");
			}
		}
		else
		{
			isTouch_EX = false;
		}
	}
	else
	{
		rcMenuMain.bottom -= 12;
		rcMenuMain.top -= 12;

		if (rcMenuMain.bottom <= 0)
		{
			rcMenuMain.top = -540;
			rcMenuMain.bottom = 0;
		}
	}
	//if (!isMenu)
	//{
		ptPlayer->update();
		ptEnemy->update();
	//}
}

void ingameScene::render()
{
	//��� �̹��� ���� - ����
	inGameBgImg->render(getMemDC(), rcIngameBg.left, rcIngameBg.top);
	//Ÿ�Ͽ� �̹��� ���� - ����
	RECT rcTemp3;

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (IntersectRect(&rcTemp3, &rcIngameWins, &sIngameTile[i].rc))
		{
			inGameTerrainImg->frameRender(getMemDC(), sIngameTile[i].rc.left, sIngameTile[i].rc.top,
				sIngameTile[i].terrainFrameX, sIngameTile[i].terrainFrameY);

			inGameObjectImg->frameRender(getMemDC(), sIngameTile[i].rc.left, sIngameTile[i].rc.top,
				sIngameTile[i].objFrameX, sIngameTile[i].objFrameY);

			//0413 ���� �ε��� ���ʹ� �������� ��ǥ�� ��Ʈ�� �׸���.
			if (sIngameTile[i].enemy.isPushed == false)continue; // ���� �־��� ���� ������ ���� �ε����� �Ѿ.
			if (sIngameTile[i].enemy.isPushed == true)
			{
				//����� �ش� ��ǥ�� �������ִ� �̹����� ����
				//�����ӷ����� ������ �����̵��� �ٲ�� �Ѵ�.
				switch (sIngameTile[i].enemy.category)
				{
				case GREY_BEAN:
					IMAGEMANAGER->findImage("ȸ�������_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLACK_BEAN:
					IMAGEMANAGER->findImage("���������_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLUE_BEAN:
					IMAGEMANAGER->findImage("�Ķ������_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLUE_FLOWER:
					IMAGEMANAGER->findImage("�Ķ���_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREEN_FLOWER:
					IMAGEMANAGER->findImage("�ʷϲ�_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case WING_TURTLE:
					IMAGEMANAGER->findImage("�����ź�_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREY_BIRD:
					IMAGEMANAGER->findImage("ȸ����_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREEN_BIRD:
					IMAGEMANAGER->findImage("�ʷϻ�_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case RED_BIRD:
					IMAGEMANAGER->findImage("������_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case DOCHI:
					IMAGEMANAGER->findImage("��ġ_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case MUSHROOM:
					IMAGEMANAGER->findImage("����_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLUE_TURTLE:
					IMAGEMANAGER->findImage("�Ķ��ź�_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREEN_TURTLE:
					IMAGEMANAGER->findImage("�ʷϰź�_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BOSS:
					IMAGEMANAGER->findImage("����_����")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				}
			}
		}
	}
	//Ÿ�� �����ֱ� - ����
	if (INPUT->GetToggleKey(VK_F1))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			FrameRect(getMemDC(), sIngameTile[i].rc, RGB(0, 0, 0));
			//FrameRect(getMemDC(), sMiniTile[i].rc, RGB(0, 255, 0));
			//Rectangle(getMemDC(), sSampleTile[i].rc);
		}
	}

	//Rectangle(getMemDC(), rcMenuMain);
	IMAGEMANAGER->findImage("�ΰ��Ӹ޴�ȭ��")->render(getMemDC(), rcMenuMain.left, rcMenuMain.top);

	//Rectangle(getMemDC(), rcMenuButtonRS);
	//Rectangle(getMemDC(), rcMenuButtonEX);
	if (isTouch_RS)
	{
		IMAGEMANAGER->findImage("�ΰ���_��ӹ�ưOn")->render(getMemDC(), rcMenuButtonRS.left, rcMenuButtonRS.top);
	}
	else
	{
		IMAGEMANAGER->findImage("�ΰ���_��ӹ�ư")->render(getMemDC(), rcMenuButtonRS.left, rcMenuButtonRS.top);
	}

	if (isTouch_EX)
	{
		IMAGEMANAGER->findImage("�ΰ���_�������ưOn")->render(getMemDC(), rcMenuButtonEX.left, rcMenuButtonEX.top);
	}
	else
	{
		IMAGEMANAGER->findImage("�ΰ���_�������ư")->render(getMemDC(), rcMenuButtonEX.left, rcMenuButtonEX.top);
	}

	ptPlayer->render();
	ptEnemy->render();
}

void ingameScene::load()
{
	HANDLE file;
	DWORD read;

	file = CreateFile("save.map", GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, sIngameTile, sizeof(tagTile) * TILEX * TILEY, &read, NULL);
	CloseHandle(file);

}

