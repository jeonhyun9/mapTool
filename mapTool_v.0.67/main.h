#pragma once
#include "gameNode.h"
/*������ ���ΰ����� ������ ���鸸 ������ �Ѵ�*/
/*������ϸ� ���ΰ��ӿ� �߰��ϱ�*/

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

