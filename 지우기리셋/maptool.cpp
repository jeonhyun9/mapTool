#include "stdafx.h"
#include "maptool.h"

HRESULT maptool::init()
{
	//타일맵 이미지 초기화
	IMAGEMANAGER->addImage("배경화면", "images/배경화면.bmp", 2000,960);
	IMAGEMANAGER->addFrameImage("지형타일1", "images/지형타일_병합.bmp", 1792, 320, 56, 10);
	IMAGEMANAGER->addFrameImage("지형타일2", "images/지형타일2_수정.bmp", 448, 320, 14, 10);
	IMAGEMANAGER->addFrameImage("지형타일3", "images/지형타일3_수정.bmp", 448, 320, 14, 10);
	IMAGEMANAGER->addFrameImage("지형타일4", "images/지형타일4_수정.bmp", 448, 320, 14, 10);
	IMAGEMANAGER->addFrameImage("오브젝트타일1", "images/오브젝트타일1_수정.bmp", 448, 320, 14, 10);
	IMAGEMANAGER->addFrameImage("오브젝트타일2", "images/오브젝트타일2_수정.bmp", 448, 320, 14, 10);
	IMAGEMANAGER->addFrameImage("오브젝트타일3", "images/오브젝트타일3_수정.bmp", 448, 320, 14, 10);
	IMAGEMANAGER->addFrameImage("오브젝트타일4", "images/오브젝트타일4_수정.bmp", 448, 320, 14, 10);
	IMAGEMANAGER->addImage("버튼_이레이저", "images/버튼_이레이저.bmp", 173, 57,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("버튼_로드", "images/버튼_로드.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("버튼_리셋", "images/버튼_리셋.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("버튼_세이브", "images/버튼_세이브.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("버튼_지형", "images/버튼_지형.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("버튼_오브젝트", "images/버튼_오브젝트.bmp", 173, 57, true, RGB(255, 0, 255));
	//밑으로 이미지추가함
	IMAGEMANAGER->addImage("버튼_이레이저온","images/버튼_이레이저온.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("버튼_로드온", "images/버튼_로드온.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("버튼_리셋온", "images/버튼_리셋온.bmp", 173, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("버튼_세이브온", "images/버튼_세이브온.bmp", 173, 57, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("버튼_지형온", "images/버튼_지형온.bmp", 173, 57, true, RGB(255, 0, 255));					//이미지 아직없음
	//IMAGEMANAGER->addImage("버튼_오브젝트온", "images/버튼_오브젝트온.bmp", 173, 57, true, RGB(255, 0, 255));

	//현재타일 초기화
	sCurrentTile.x = 4;
	sCurrentTile.y = 4;
	sToolBox.moveSpeed = 5;
	sToolBox.toggle = false;
	sToolBox.selectedPage = 1;

	//타일 셋업
	this->tileSetup();

	//초기 선택 값 = 지형
	ctrlSelect = CTRL_TERRAIN;

	//드래그 초기화
	isDrag = false;
	saveX = saveY = 0;

	
	//버튼박스클릭 - 버튼클릭했을때 이미지변경 불변수
	isSave = false;
	isLoad = false;
	isObject = false;
	isTerrain = false;
	isDragBox = false;
	isErase = false;
	isReset = false;

	return S_OK;
}

void maptool::release()
{
}

void maptool::update()
{
	this->toolBoxUpdate();


	if (INPUT->GetToggleKey('D'))
	{
		if (INPUT->GetKeyDown(VK_LBUTTON))
		{
			isDrag = true;
			saveX = _ptMouse.x;
			saveY = _ptMouse.y;

			if (PtInRect(&sToolBtn.rcSave, _ptMouse))
			{
				isSave = true;		//추가 세이브눌렀을때 이미지 변경해줌
				this->save();
			}
			if (PtInRect(&sToolBtn.rcLoad, _ptMouse))
			{
				isLoad = true;		//추가 로드눌렀을때 이미지 변경해줌
				this->load();
			}

			if (PtInRect(&sToolBtn.rcDelete, _ptMouse))
			{
				if (isErase == false)		//추가 이레이저 눌렀을때 이미지 변경해줌 
				{
					isErase = true;
				}
				else
				{
					isErase = false;
				}

				ctrlSelect = CTRL_ERASER;
			}
		}
		if (INPUT->GetKey(VK_LBUTTON))
		{
			dragRc = RectMake(saveX, saveY, (_ptMouse.x - saveX), (_ptMouse.y - saveY));
		}

		if (INPUT->GetKeyUp(VK_LBUTTON))		//겟키업으로 눌렀을때 true 값 fasle처리해주기
		{
			isDrag = false;
			isSave = false;
			isLoad = false;
			isReset = false;
		}
	}
	else
	{
		//좌클릭시 해당 위치에 선택된 타일 그리기
		if (INPUT->GetKey(VK_LBUTTON)) this->setMap();

		//버튼 클릭 충돌 처리
		if (INPUT->GetKeyDown(VK_LBUTTON))
		{
			if (PtInRect(&sToolBtn.rcSave, _ptMouse))
			{
				isSave = true;		//추가 세이브 눌렀을때 이미지 변경해줌
				this->save();
			}
			if (PtInRect(&sToolBtn.rcLoad, _ptMouse))
			{
				isLoad = true;		//추가 로드 눌렀을때 이미지 변경해줌
				this->load();
			}

			if (PtInRect(&sToolBtn.rcDelete, _ptMouse))
			{
				if (isErase == false)		//추가 이레이저 눌렀을때 이미지 변경해줌
				{
					isErase = true;
				}
				else
				{
					isErase = false;		//이레이저는 다시 눌러주면 풀림
				}
				ctrlSelect = CTRL_ERASER;
			}
			
			if (PtInRect(&sToolBtn.rcLeftPointer, _ptMouse) && sToolBox.selectedPage >= 2)
			{
				sToolBox.selectedPage--;
			}
			if (PtInRect(&sToolBtn.rcRightPointer, _ptMouse) && sToolBox.selectedPage < 4)
			{
				sToolBox.selectedPage++;
			}
			if (PtInRect(&sToolBtn.rcTerrain, _ptMouse))
			{
				//isTerrain = true;
				ctrlSelect = CTRL_TERRAIN;
			}
			if (PtInRect(&sToolBtn.rcObject, _ptMouse))
			{
				//isObject = true;
				ctrlSelect = CTRL_OBJECT;
			}
			if (PtInRect(&sToolBtn.rcReset, _ptMouse))		//리셋버튼만들어서 피티인렉해줌
			{
				isReset = true;								
				isErase = false;						
				ctrlSelect = CTRL_RESET;
			}
		}
		if (INPUT->GetKeyUp(VK_LBUTTON))					//세이브,로드,리셋버튼 false 겟키업 추가
		{
			isSave = false;
			isLoad = false;
			isReset = false;
		}

	}
}

void maptool::render()
{
	IMAGEMANAGER->render("배경화면", getMemDC(), 0, 0);
	//인게임화면 지형을 그린다
	for (int i = 0; i < TILEX * TILEY; i++)
	{
			IMAGEMANAGER->frameRender("지형타일1", getMemDC(), sTile[i].rc.left, sTile[i].rc.top,
				sTile[i].terrainFrameX, sTile[i].terrainFrameY);
	}
	
	if (isDrag)
	{
		//Rectangle(getMemDC(), dragRc);
		FrameRect(getMemDC(), dragRc, RGB(255, 0, 0));
	}
	else
	{
		//인게임화면 렉트틀과 충돌했냐?
		RECT _tempRc;
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			if (IntersectRect(&_tempRc, &sTile[i].rc, &dragRc))
			{
				//현재버튼이 지형이냐?
				if (ctrlSelect == CTRL_TERRAIN)
				{
					sTile[i].terrainFrameX = sCurrentTile.x;
					sTile[i].terrainFrameY = sCurrentTile.y;
					sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
				}
				//현재버튼이 오브젝트냐?
				if (ctrlSelect == CTRL_OBJECT)
				{
					sTile[i].objFrameX = sCurrentTile.x;
					sTile[i].objFrameY = sCurrentTile.y;
					sTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);
				}
				//현재버튼이 지우개냐?
				if (ctrlSelect == CTRL_ERASER)
				{
					if (isErase)								//erase로직 추가
					{
						sTile[i].terrainFrameX = 10;
						sTile[i].terrainFrameY = 9;
						//sTile[i].terrain = OBJ_NONE;
					}
				}
			}
		}
	}

	
	//F1 입력시 인게임화면 렉트 보여주기
	if (INPUT->GetToggleKey(VK_F1))
	{
		for (int i = 0; i < TILEX * TILEY; i++)
		{
			FrameRect(getMemDC(), sTile[i].rc, RGB(0, 0, 0));
			//Rectangle(getMemDC(), sSampleTile[i].rc);
		}
	}
	
	//F2 입력시 툴박스 + 페이지 + 버튼 렉트 보여주기
	if (INPUT->GetToggleKey(VK_F2))
	{
		Rectangle(getMemDC(), sToolBox.rcBack);
		Rectangle(getMemDC(), sToolBox.rcPage);
		Rectangle(getMemDC(), sToolBtn.rcLoad);
		IMAGEMANAGER->render("버튼_로드", getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		Rectangle(getMemDC(), sToolBtn.rcSave);
		IMAGEMANAGER->render("버튼_세이브", getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		Rectangle(getMemDC(), sToolBtn.rcReset);
		IMAGEMANAGER->render("버튼_리셋", getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		Rectangle(getMemDC(), sToolBtn.rcDelete);
		IMAGEMANAGER->render("버튼_이레이저", getMemDC(), sToolBtn.rcDelete.left, sToolBtn.rcDelete.top);
		Rectangle(getMemDC(), sToolBtn.rcTerrain);
		IMAGEMANAGER->render("버튼_지형", getMemDC(), sToolBtn.rcTerrain.left, sToolBtn.rcTerrain.top);
		Rectangle(getMemDC(), sToolBtn.rcObject);
		IMAGEMANAGER->render("버튼_오브젝트", getMemDC(), sToolBtn.rcObject.left, sToolBtn.rcObject.top);
		Rectangle(getMemDC(), sToolBtn.rcLeftPointer);
		Rectangle(getMemDC(), sToolBtn.rcRightPointer);


		//눌렀을때 버튼 변환 로직 추가
		if (isLoad)
		{
			IMAGEMANAGER->render("버튼_로드온", getMemDC(), sToolBtn.rcLoad.left, sToolBtn.rcLoad.top);
		}
		if (isSave)
		{
			IMAGEMANAGER->render("버튼_세이브온", getMemDC(), sToolBtn.rcSave.left, sToolBtn.rcSave.top);
		}
		if (isReset)
		{
			IMAGEMANAGER->render("버튼_리셋온", getMemDC(), sToolBtn.rcReset.left, sToolBtn.rcReset.top);
		}
		if (isErase)
		{
			IMAGEMANAGER->render("버튼_이레이저온", getMemDC(), sToolBtn.rcDelete.left, sToolBtn.rcDelete.top);
		}
		//if (isTerrain)
		//{
		//	IMAGEMANAGER->render("버튼_지형온", getMemDC(), sToolBtn.rcTerrain.left, sToolBtn.rcTerrain.top);
		//}
		//if (isObject)
		//{
		//	IMAGEMANAGER->render("버튼_오브젝트온", getMemDC(), sToolBtn.rcObject.left, sToolBtn.rcObject.top);
		//}

		switch (sToolBox.selectedPage)
		{
		case 1:
			if (ctrlSelect==CTRL_TERRAIN)
			{
				IMAGEMANAGER->render("지형타일1", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("오브젝트타일1", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			break;
		case 2:
			if (ctrlSelect == CTRL_TERRAIN)
			{
				IMAGEMANAGER->render("지형타일2", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("오브젝트타일2", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			break;
		case 3:
			if (ctrlSelect == CTRL_TERRAIN)
			{
				IMAGEMANAGER->render("지형타일3", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("오브젝트타일3", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			break;
		case 4:
			if (ctrlSelect == CTRL_TERRAIN)
			{
				IMAGEMANAGER->render("지형타일4", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			else if (ctrlSelect == CTRL_OBJECT)
			{
				IMAGEMANAGER->render("오브젝트타일4", getMemDC(), sToolBox.rcBack.left + 15, sToolBox.rcBack.top + 15);
			}
			break;
		}
		
		for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
		{
			//Rectangle(getMemDC(), sSampleTile[i].rc);
			FrameRect(getMemDC(), sSampleTile_1[i].rc, RGB(255, 255, 0));
		}

		//툴박스 표시되어 있을 때 화살표 입력시 툴박스 상하좌우 이동
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

		sToolBox.toggle = true;
	}
	else
	{
		sToolBox.toggle = false;
	}

}

void maptool::tileSetup()
{
	//툴박스 초기화
	sToolBox.toggle = false;
	sToolBox.x = WINSIZEX/2;
	sToolBox.y = 670;
	sToolBox.width = 1000;
	sToolBox.height = 400;

	//페이지 초기화
	sToolBox.pageWidth = 480;
	sToolBox.pageHeight = 400;

	//툴버튼 초기화
	sToolBtn.width = 173;
	sToolBtn.height = 53;

	//타일 렉트 초기화
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			sTile[i * TILEX + j].rc = RectMake(j * TILESIZE, i * TILESIZE, TILESIZE, TILESIZE);
			sTile[i * TILEX + j].currentTerrain = TERRAIN_NONE;
		}
	}

	//오른쪽 샘플타일 렉트 초기화
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			sSampleTile_1[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcPage.left + j * TILESIZE, sToolBox.rcPage.top + i * TILESIZE, TILESIZE, TILESIZE);
			sSampleTile_1[i * SAMPLETILEX + j].terrainFrameX = j;
			sSampleTile_1[i * SAMPLETILEX + j].terrainFrameY = i;
		}
	}

	//타일의 초기화면 
	//for (int i = 0; i < TILEX * TILEY; i++)
	//{
	//	sTile[i].terrainFrameX = 9; //지형 타일 X좌표
	//	sTile[i].terrainFrameY = 1; //지형 타일 Y좌표
	//	sTile[i].objFrameX = 0; //오브젝트 타일 X좌표
	//	sTile[i].objFrameY = 0; //오브젝트 타일 Y좌표
	//	sTile[i].terrain = terrainSelect(sTile[i].terrainFrameX, sTile[i].terrainFrameY); //해당 X,Y 좌표 값 가진 타일 선택
	//	sTile[i].obj = OBJ_NONE; //오브젝트 선택안한 상태
	//}
}

void maptool::setMap()
{
	for (int i = 0; i < SAMPLETILEX * SAMPLETILEY; i++)
	{
		if (sToolBox.toggle == false)continue; //토글키 안누르면 충돌처리를 하지 않는다.
		if (PtInRect(&sSampleTile_1[i].rc, _ptMouse))
		{
			sCurrentTile.x = sSampleTile_1[i].terrainFrameX;
			sCurrentTile.y = sSampleTile_1[i].terrainFrameY;
			break;
		}

	}

	//인게임화면 렉트틀과 충돌했냐?
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (PtInRect(&sTile[i].rc, _ptMouse))
		{
			//현재버튼이 지형이냐?
			if (ctrlSelect == CTRL_TERRAIN)
			{
				sTile[i].terrainFrameX = sCurrentTile.x;
				sTile[i].terrainFrameY = sCurrentTile.y;
				sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
			}
			//현재버튼이 오브젝트냐?
			if (ctrlSelect == CTRL_OBJECT)
			{
				sTile[i].objFrameX = sCurrentTile.x;
				sTile[i].objFrameY = sCurrentTile.y;
				sTile[i].obj = objectSelect(sCurrentTile.x, sCurrentTile.y);
			}
			//현재버튼이 지우개냐?
			if (ctrlSelect == CTRL_ERASER)							//이레이저 로직추가
			{
				if (isErase)
				{
					sTile[i].terrainFrameX = 10;
					sTile[i].terrainFrameY = 9;
					//sTile[i].obj = OBJ_NONE;
				}
			}
			if (ctrlSelect == CTRL_RESET)							//리셋 로직 추가
			{
				for (int i = 0; i < TILEX * TILEY; i++)
				{	
					sTile[i].terrainFrameX = 10;
					sTile[i].terrainFrameY = 9;
					sTile[i].terrain = terrainSelect(sCurrentTile.x, sCurrentTile.y);
				}
				ctrlSelect = CTRL_TERRAIN;
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
	//툴박스 배경 렉트 생성
	sToolBox.rcBack = RectMakeCenter(sToolBox.x, sToolBox.y, sToolBox.width, sToolBox.height);

	//툴박스 페이지 렉트 생성
	sToolBox.rcPage = RectMake(sToolBox.rcBack.left, sToolBox.rcBack.top, sToolBox.pageWidth, sToolBox.pageHeight);

	//툴박스 버튼 렉트 생성
	sToolBtn.rcDelete = RectMake(sToolBox.x + 60, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcReset = RectMake(sToolBox.x + 250, sToolBox.y - 60, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcSave = RectMake(sToolBox.x + 60, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLoad = RectMake(sToolBox.x + 250, sToolBox.y - 130, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcTerrain = RectMake(sToolBox.x + 60, sToolBox.y + 10, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcObject = RectMake(sToolBox.x + 250, sToolBox.y + 10, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcLeftPointer = RectMake(sToolBox.x - 450, sToolBox.y + 140, sToolBtn.width, sToolBtn.height);
	sToolBtn.rcRightPointer = RectMake(sToolBox.x - 250, sToolBox.y + 140, sToolBtn.width, sToolBtn.height);
	

	//오른쪽 샘플타일 렉트 업데이트
	for (int i = 0; i < SAMPLETILEY; i++)
	{
		for (int j = 0; j < SAMPLETILEX; j++)
		{
			sSampleTile_1[i * SAMPLETILEX + j].rc = RectMake(sToolBox.rcBack.left + 15 + j * TILESIZE, sToolBox.rcBack.top + 15 + i * TILESIZE, TILESIZE, TILESIZE);
		}
	}

	//if(sToolBox.toggle)

}

TERRAIN maptool::terrainSelect(int frameX, int frameY)
{
	//시멘트
	if (frameX == 1 && frameY == 0)
	{
		return TR_CEMENT;
	}
	//땅
	if (frameX == 2 && frameY == 0)
	{
		return TR_GROUND;
	}
	//잔디
	if (frameX == 3 && frameY == 0)
	{
		return TR_GRASS;
	}
	//물
	if (frameX == 4 && frameY == 0)
	{
		return TR_WATER;
	}

	//기타
	return TR_GROUND;
}

OBJECT maptool::objectSelect(int frameX, int frameY)
{
	return  OBJ_BLOCKS;
}

