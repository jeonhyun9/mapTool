#pragma once
#include "gameNode.h"



class player : public gameNode
{
private:
	tagPlayer sPlayer;

	float gravity; //�߷�

	int frameIdx;
	int frameCnt;

	//�Һ���
	bool isJump; //������?
	bool isRight; //�������̴�?

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void playerAnimation();

	player() {}
	~player() {}
};

