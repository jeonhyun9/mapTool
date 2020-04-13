#include "stdafx.h"
#include "ingameScene.h"

HRESULT ingameScene::init()
{
	ptPlayer = new player;
	ptPlayer->init();

	ptEnemy = new enemy;
	ptEnemy->init();

	//백그라운드 렉트 - 이준
	rcIngameBg = RectMake(0, 0, 6000, 960);
	inGameBgImg = IMAGEMANAGER->findImage("백그라운드");

	//인게임 로드 이미지 - 이준
	inGameTerrainImg = IMAGEMANAGER->findImage("지형타일_병합");
	inGameObjectImg = IMAGEMANAGER->findImage("오브젝트타일_병합");

	//윈사이즈 렉트 - 이준
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
	//함수 추가 - 이준
	this->load();

	//타일 렉트 초기화 - 이준
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
	//배경 이미지 렌더 - 이준
	inGameBgImg->render(getMemDC(), rcIngameBg.left, rcIngameBg.top);
	//타일에 이미지 렌더 - 이준
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

		//0413 현구 로드한 에너미 데이터의 좌표에 렉트를 그린다.
		if (sIngameTile[i].enemy.isPushed == false)continue; // 값이 넣어져 있지 않으면 다음 인덱스로 넘어감.
		if (sIngameTile[i].enemy.isPushed == true)
		{
			//현재는 해당 좌표에 멈춰져있는 이미지만 렌더
			//프레임렌더로 실제로 움직이도록 바꿔야 한다.
			switch (sIngameTile[i].enemy.category)
			{
				case GREY_BEAN:
					IMAGEMANAGER->findImage("회색콩벌레_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLACK_BEAN:
					IMAGEMANAGER->findImage("검은콩벌레_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLUE_BEAN:
					IMAGEMANAGER->findImage("파란콩벌레_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLUE_FLOWER:
					IMAGEMANAGER->findImage("파란꽃_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREEN_FLOWER:
					IMAGEMANAGER->findImage("초록꽃_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case WING_TURTLE:
					IMAGEMANAGER->findImage("날개거북_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREY_BIRD:
					IMAGEMANAGER->findImage("회색새_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREEN_BIRD:
					IMAGEMANAGER->findImage("초록새_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case RED_BIRD:
					IMAGEMANAGER->findImage("빨간새_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case DOCHI:
					IMAGEMANAGER->findImage("도치_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case MUSHROOM:
					IMAGEMANAGER->findImage("버섯_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BLUE_TURTLE:
					IMAGEMANAGER->findImage("파란거북_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case GREEN_TURTLE:
					IMAGEMANAGER->findImage("초록거북_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
				case BOSS:
					IMAGEMANAGER->findImage("보스_수정")->render(getMemDC(), sIngameTile[i].enemy.x, sIngameTile[i].enemy.y);
					break;
			}

		}
	}
	//타일 보여주기 - 이준
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

