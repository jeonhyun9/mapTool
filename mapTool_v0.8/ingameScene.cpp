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
	return S_OK;
}

void ingameScene::release()
{
	ptPlayer->release();
	ptEnemy->release();
}

void ingameScene::update()
{
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

	ptPlayer->update();
	ptEnemy->update();
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
		}

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

