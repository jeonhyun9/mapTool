#include "stdafx.h"
#include "loadingScene.h"

HRESULT loadingScene::init()
{
	//로딩클래스 초기화
	_loading = new loading;
	_loading->init();

	//로딩 이미지 및 사운드 초기화
	this->loadingImage();
	this->loadingSound();

	//로딩 마리오 이미지
	IMAGEMANAGER->addFrameImage("로딩마리오", "images/마리오액션.bmp", 99, 60, 3, 1);
	count = index = 0;
	return S_OK;
}

void loadingScene::release()
{
	//로딩클래스 해제
	_loading->release();
	SAFE_DELETE(_loading);
}

void loadingScene::update()
{
	//로딩클래스 업데이트
	_loading->update();

	//로딩완료후 화면 변경
	if (_loading->loadingDone())
	{
		SCENEMANAGER->loadScene("메뉴");
	}
	count++;
	IMAGEMANAGER->findImage("로딩마리오")->setFrameY(0);
	if (count % 5 == 0)
	{
		index++;
		if (index > 3)
		{
			index = 0;
		}
		IMAGEMANAGER->findImage("로딩마리오")->setFrameX(index);
	}

}

void loadingScene::render()
{
	//로딩클래스 렌더
	_loading->render();

	for (int i = 0; i < _loading->getLoadItem().size(); i++)
	{
		if (_loading->getLoadItem()[i]->getLoadKind() == LOAD_KIND_IMAGE_0) continue;
		sprintf(_LoadFileName, _loading->getLoadItem()[i]->getImageResource().fileName);
	}

	SetBkMode(getMemDC(), TRANSPARENT);
	TextOut(getMemDC(), 570, 802, _LoadFileName, strlen(_LoadFileName));

	IMAGEMANAGER->findImage("로딩마리오")->frameRender(getMemDC(), _loading->getProgressBar()->getWidth() + 470, 740);
}


//로딩이미지 함수(이곳에 이미지를 전부 넣어라)
void loadingScene::loadingImage()
{
	//_loading->loadImage("백그라운드", "Images/background.bmp", WINSIZEX, WINSIZEY);
	//_loading->loadFrameImage("ufo", "Images/ufo.bmp", 530, 32, 10, 1);
	//_loading->loadImage("bullet", "Images/bullet.bmp", 21, 21);

	_loading->loadFrameImage("지형타일_병합", "images/지형타일_병합.bmp", 1792, 320, 56, 10);
	_loading->loadFrameImage("지형타일_병합미니", "images/지형타일_병합미니.bmp", 179, 32, 56, 10);

	_loading->loadFrameImage("지형타일1", "images/지형타일1_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("지형타일2", "images/지형타일2_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("지형타일3", "images/지형타일3_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("지형타일4", "images/지형타일4_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);

	_loading->loadFrameImage("오브젝트타일1", "images/오브젝트타일1_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("오브젝트타일2", "images/오브젝트타일2_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("오브젝트타일3", "images/오브젝트타일3_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("오브젝트타일4", "images/오브젝트타일4_수정.bmp", 448, 320, SAMPLETILEX, SAMPLETILEY);
	_loading->loadFrameImage("오브젝트타일_병합", "images/오브젝트타일_병합.bmp", 1792, 320, 56, 10); // 타일 병합 이미지 추가 -동주
	_loading->loadFrameImage("오브젝트타일_병합미니", "images/오브젝트타일_병합미니.bmp", 179, 32, 56, 10); // 미니타일 병합 이미지 추가 -동주 

	_loading->loadImage("툴박스", "images/툴박스.bmp", 1000, 450, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_이레이저", "images/버튼_이레이저.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_로드", "images/버튼_로드.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_리셋", "images/버튼_리셋.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_세이브", "images/버튼_세이브.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_지형", "images/버튼_지형.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_오브젝트", "images/버튼_오브젝트.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_드래그", "images/버튼_드래그.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_플레이어", "images/버튼_플레이어.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_에너미", "images/버튼_에너미.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_엑시트", "images/버튼_엑시트.bmp", 173, 57, true, RGB(255, 0, 255));

	_loading->loadImage("버튼_이레이저온", "images/버튼_이레이저온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_로드온", "images/버튼_로드온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_리셋온", "images/버튼_리셋온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_세이브온", "images/버튼_세이브온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_지형온", "images/버튼_지형온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_오브젝트온", "images/버튼_오브젝트온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_드래그온", "images/버튼_드래그온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_플레이어온", "images/버튼_플레이어온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_에너미온", "images/버튼_에너미온.bmp", 173, 57, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_엑시트온", "images/버튼_엑시트온.bmp", 173, 57, true, RGB(255, 0, 255));

	_loading->loadImage("버튼_왼쪽화살표", "images/버튼_왼쪽화살표.bmp", 51, 60, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_오른쪽화살표", "images/버튼_오른쪽화살표.bmp", 51, 60, true, RGB(255, 0, 255));

	_loading->loadImage("버튼_왼쪽화살표온", "images/버튼_왼쪽화살표온.bmp", 51, 60, true, RGB(255, 0, 255));
	_loading->loadImage("버튼_오른쪽화살표온", "images/버튼_오른쪽화살표온.bmp", 51, 60, true, RGB(255, 0, 255));

	_loading->loadImage("백그라운드", "images/배경화면3배.bmp", 6000, 960); //변경 >> 가로사이즈 3배 - 동주
	_loading->loadImage("미니맵", "images/배경화면3배미니.bmp", 600, 96); //변경 >> 가로사이즈 3배 - 동주
	
	_loading->loadImage("메뉴백그라운드", "images/MenuBackGround.bmp", 1600, 960);
	_loading->loadImage("플레이버튼", "images/플레이버튼_off.bmp", 278, 90);
	_loading->loadImage("플레이온버튼", "images/플레이버튼_on.bmp", 293, 95);
	_loading->loadImage("맵툴버튼", "images/맵툴버튼_off.bmp", 278, 90);
	_loading->loadImage("맵툴온버튼", "images/맵툴버튼_on.bmp", 293, 95);
	_loading->loadImage("나가기버튼", "images/나가기버튼_off.bmp", 278, 90);
	_loading->loadImage("나가기온버튼", "images/나가기버튼_on.bmp", 293, 95);
																
	//로딩이 너무 빠르게 진행되서 천천히 돌아가도록 테스트용으로 만들기
	for (int i = 0; i < 100; i++)
	{
		_loading->loadImage("테스트", WINSIZEX, WINSIZEY);
	}
}

//로딩사운드 함수(이곳에 사운드를 전부 넣어라)
void loadingScene::loadingSound()
{
}
