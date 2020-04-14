#include "stdafx.h"
#include "ingameScene.h"

HRESULT ingameScene::init()
{
	ptPlayer = new player;
	ptPlayer->init();

	//ptEnemy = new enemy;
	//ptEnemy->init();

	//백그라운드 렉트 - 이준
	rcIngameBg = RectMake(0, 0, 6000, 960);
	inGameBgImg = IMAGEMANAGER->findImage("백그라운드");

	//인게임 로드 이미지 - 이준
	inGameTerrainImg = IMAGEMANAGER->findImage("지형타일_병합");
	inGameObjectImg = IMAGEMANAGER->findImage("오브젝트타일_병합");

	//윈사이즈 렉트 - 이준
	rcIngameWins = RectMake(0, 0, WINSIZEX, WINSIZEY);

	//메뉴관련 변수 - 이준 0413
	menuX = WINSIZEX / 2;
	menuY = -256;
	//메뉴 렉트 초기화 - 이준 0413
	rcMenuMain = RectMakeCenter(WINSIZEX / 2, -270, 594, 540);
	isMenu = false;
	isTouch_RS = false;
	isTouch_EX = false;

	//-------------------------------------에너미 초기화
	//콩벌레 구조체 초기화
	sBean.x = WINSIZEX / 2;
	sBean.y = WINSIZEY / 2;
	beanleft = false;
	beanright = true;

	//물고기 구조체 초기화
	sBird.x = 700;
	sBird.y = 700;
	sBird.angle = PI_2;
	sBird.speed = 5.0f;
	sBird.jumpSpeed = 16.0f;
	_fishleft = false;
	_fishright = true;
	gravity = 0;

	//버섯 구조체 초기화
	sMushroom.x = 800;
	sMushroom.y = 850;
	_mushroomleft = true;

	//꽃 구조체 초기화
	sFlower.x = 500;
	sFlower.y = 700;
	sFlower.angle = PI_2;
	sFlower.speed = 3.0f;
	sFlower.jumpSpeed = 16.0f;
	flowerG = 0;
	flowerJump = false;

	//보스 구조체 초기화
	sBoss.x = 0;
	sBoss.y = 0;
	sBoss.angle = PI_2;
	sBoss.speed = 5.0f;
	sBoss.jumpSpeed = 16.0f;
	bossG = 0;
	bossJump = false;
	bossleft = false;
	bossright = true;

	//구조체 렉트 초기화
	sBean.rc = RectMake(sBean.x, sBean.y, 64, 64);
	sBird.rc = RectMake(sBird.x, sBird.y, 64, 64);
	sMushroom.rc = RectMake(sMushroom.x, sMushroom.y, 64, 64);
	sFlower.rc = RectMake(sFlower.x, sFlower.y, 64, 96);
	sBoss.rc = RectMake(sBoss.x, sBoss.y, 128, 128);

	//카운트값 초기화
	count = 0;
	imgCount = 0;
	imgIndex = 0;

	imgCount2 = 0;
	imgIndex2 = 0;

	sEnemyState = ENEMYRUN;

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		isRender[i] = false;
	}

	return S_OK;
}

void ingameScene::release()
{
	ptPlayer->release();
	//ptEnemy->release();
}

void ingameScene::update()
{
	
	rcMenuButtonRS = RectMake(rcMenuMain.left + 240, rcMenuMain.top + 220, 170, 62);
	rcMenuButtonEX = RectMake(rcMenuMain.left + 240, rcMenuMain.top + 320, 170, 62);

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

	//ESC 버튼 추가 - 이준0413
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
				SCENEMANAGER->loadScene("메뉴");
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
		//ptEnemy->update();
	//}

	//----------------------------------------------------에너미 업데이트
	count++;
	// 새 점프 모션
	sBird.rc = RectMake(sBird.x, sBird.y, 64, 64);
	//버섯 움직임 
	sMushroom.rc = RectMake(sMushroom.x, sMushroom.y, 64, 64);
	//꽃 움직임 
	sFlower.rc = RectMake(sFlower.x, sFlower.y, 50, 50);
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (sIngameTile[i].enemy.isPushed == false)continue;
		//보스 움직임
		switch (sIngameTile[i].enemy.category)
		{
		case GREY_BEAN:
			sBean.x = sIngameTile[i].enemy.x;
			sBean.y = sIngameTile[i].enemy.y;
		case BOSS:
			sBoss.x = sIngameTile[i].enemy.x;
			sBoss.y = sIngameTile[i].enemy.y;
		}
	}
	sBoss.rc = RectMake(sBoss.x, sBoss.y, 128, 128);
	sBean.rc = RectMake(sBean.x, sBean.y, 64, 64);
	

	this->enemyAnimation();
	this->bossAttackMove();
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

			//0413 현구 로드한 에너미 데이터의 좌표에 렉트를 그린다.
			if (sIngameTile[i].enemy.isPushed == false)continue; // 값이 넣어져 있지 않으면 다음 인덱스로 넘어감.
			if (sIngameTile[i].enemy.isPushed == true)
			{
				//현재는 해당 좌표에 멈춰져있는 이미지만 렌더
				//프레임렌더로 실제로 움직이도록 바꿔야 한다.
				switch (sIngameTile[i].enemy.category)
				{
				case GREY_BEAN:
					IMAGEMANAGER->findImage("회색콩벌레")->frameRender(getMemDC(), sBean.x, sBean.y);
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
					IMAGEMANAGER->findImage("보스")->frameRender(getMemDC(), sBoss.rc.left, sBoss.rc.top);
					break;
				}
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

	//Rectangle(getMemDC(), rcMenuMain);
	IMAGEMANAGER->findImage("인게임메뉴화면")->render(getMemDC(), rcMenuMain.left, rcMenuMain.top);

	//Rectangle(getMemDC(), rcMenuButtonRS);
	//Rectangle(getMemDC(), rcMenuButtonEX);
	if (isTouch_RS)
	{
		IMAGEMANAGER->findImage("인게임_계속버튼On")->render(getMemDC(), rcMenuButtonRS.left, rcMenuButtonRS.top);
	}
	else
	{
		IMAGEMANAGER->findImage("인게임_계속버튼")->render(getMemDC(), rcMenuButtonRS.left, rcMenuButtonRS.top);
	}

	if (isTouch_EX)
	{
		IMAGEMANAGER->findImage("인게임_나가기버튼On")->render(getMemDC(), rcMenuButtonEX.left, rcMenuButtonEX.top);
	}
	else
	{
		IMAGEMANAGER->findImage("인게임_나가기버튼")->render(getMemDC(), rcMenuButtonEX.left, rcMenuButtonEX.top);
	}

	//확인용 렉트
	//Rectangle(getMemDC(), sBean.rc);//콩벌레
	Rectangle(getMemDC(), sBird.rc);//물고기 
	Rectangle(getMemDC(), sMushroom.rc);//버섯
	Rectangle(getMemDC(), sFlower.rc);//꽃
	//Rectangle(getMemDC(), sBoss.rc);//보스

	ptPlayer->render();
	//ptEnemy->render();
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

void ingameScene::enemyAnimation()
{
	//switch (sEnemyState)
	//{
	//case ENEMYRUN:
		//왼쪽 프레임 애니메이션
		if (bossleft)
		{
			imgCount++;
			IMAGEMANAGER->findImage("보스")->setFrameY(1);
			if (imgCount % 6 == 0)
			{
				imgIndex--;
				if (imgIndex < 0)
				{
					imgIndex = 4;
				}
				IMAGEMANAGER->findImage("보스")->setFrameX(imgIndex);
			}
		}
		else //오른쪽 프레임 애니메이션
		{
			imgCount++;
			IMAGEMANAGER->findImage("보스")->setFrameY(0);
			if (imgCount % 6 == 0)
			{
				imgIndex++;
				if (imgIndex > 4)
				{
					imgIndex = 0;
				}
				IMAGEMANAGER->findImage("보스")->setFrameX(imgIndex);
			}
		}

		if (beanleft)
		{
			imgCount2++;
			IMAGEMANAGER->findImage("회색콩벌레")->setFrameY(1);
			if (imgCount2 % 6 == 0)
			{
				imgIndex2--;
				if (imgIndex2 < 0)
				{
					imgIndex2 = 2;
				}
				IMAGEMANAGER->findImage("회색콩벌레")->setFrameX(imgIndex2);
			}
		}
		else //오른쪽 프레임 애니메이션
		{
			imgCount2++;
			IMAGEMANAGER->findImage("회색콩벌레")->setFrameY(0);
			if (imgCount2 % 6 == 0)
			{
				imgIndex2++;
				if (imgIndex2 > 2)
				{
					imgIndex2 = 0;
				}
				IMAGEMANAGER->findImage("회색콩벌레")->setFrameX(imgIndex2);
			}
		}

	//	break;
	//case ENEMYDIE:
	//
	//	break;
	//
	//case ENEMYATT:
	//	break;
	//
	//}
}

void ingameScene::bossAttackMove()
{
}

