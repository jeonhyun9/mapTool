#pragma once
#include "gameNode.h"



class player : public gameNode
{
private:
	tagPlayer sPlayer;

	float gravity; //중력

	int frameIdx;
	int frameCnt;

	//불변수
	bool isJump; //점프냐?
	bool isRight; //오른쪽이니?

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void playerAnimation();

	player() {}
	~player() {}
};

