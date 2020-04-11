#pragma once
#include "gameNode.h"
/*앞으로 메인게임은 각각의 씬들만 관리를 한다*/
/*헤더파일만 메인게임에 추가하기*/

#include "maptoolScene.h"
#include "maptool.h"
#include "loadingScene.h"
#include "menuScene.h"
#include "ingameScene.h"


class main : public gameNode
{
public:
	HRESULT init();
	void release();
	void update();
	void render();

	main() {}
	~main() {}
};

