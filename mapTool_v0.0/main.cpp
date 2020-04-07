#include "stdafx.h"
#include "main.h"

//=============================================================
//	## 초기화 ## init()
//=============================================================
HRESULT main::init()
{
	gameNode::init();
	//클래스 초기화를 이곳에서 한다
	
	/*앞으로 메인게임은 가각의 씬들만 관리를 한다*/
	//각각의 씬들은 메인게임 역할을 한다

	/*씬추가*/
	SCENEMANAGER->addScene("맵툴기초", new maptoolScene);
	SCENEMANAGER->addScene("맵툴", new maptool);
	

	/*현재씬 설정*/
	SCENEMANAGER->loadScene("맵툴기초");
	//SCENEMANAGER->loadScene("맵툴");


	return S_OK;
}

//=============================================================
//	## 해제 ## release()
//=============================================================
void main::release()
{
	gameNode::release();

}

//=============================================================
//	## 업데이트 ## update()
//=============================================================
void main::update()
{
	gameNode::update();
	
	//씬매니져 업데이트
	SCENEMANAGER->update();
}

//=============================================================
//	## 렌더 ## render()
//=============================================================
void main::render()
{
	//흰색 빈 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================	
	
	//글자색 배경 없애기
	SetBkMode(getMemDC(), TRANSPARENT);
	//씬매니져 렌더
	SCENEMANAGER->render();

//=============================================================
	//백버퍼의 내용을 화면DC에 그린다
	this->getBackBuffer()->render(getHDC());
}
