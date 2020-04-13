#pragma once
#include "gameNode.h"
class menuScene : public gameNode
{
private:
	image* menuBgImg;
	image* buttonPlayImg;
	image* buttonPlayOnImg;
	image* buttonMapToolImg;
	image* buttonMapToolOnImg;
	image* buttonQuitImg;
	image* buttonQuitOnImg;

	RECT rcPlay;
	RECT rcMapTool;
	RECT rcQuit;

	bool playBtTouch;
	bool mapToolBtTouch;
	bool QuitBtTouch;
public:
	HRESULT init();
	void release();
	void update();
	void render();
};

