#include "DXUT.h"
#include "Ingame.h"

extern int score; // 다른 파일에서 score를 받아온다.

Ingame::Ingame(int type)
	: type(type) // 초기화
{
}

void Ingame::Init()
{
	type = VMGR->stage;

	if (!isReady)
		return;

	OBJ->Add(new Mouse, "Mouse"); // 마우스 오브젝트 생성

	switch (type) // type에 따S른 스테이지 설정
	{
	case 1:
		Player::coloring_per = 0; // 퍼센트 초기화
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER; // 보스 생성
		enemy_count = 3;
		score = 0; // 점수 초기화
		break;
	case 2:
		VMGR->stage = 2;
		Player::coloring_per = 0;
		enemy_count = 5;
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER;
		break;
	case 3:
		VMGR->stage = 3;
		Player::coloring_per = 0;
		enemy_count = 10;
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER;
		break;
	}
	OBJ->Add(new Player, "player")->pos = { CENTER.x, float(B) }; // 플레이어 생성

	for (size_t i = 0; i < enemy_count; i++)
		OBJ->Add(new Enemy(RANDOM->INT(1, 3)), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
	//OBJ->Add(new Enemy(RANDOM->INT(type * 3 - 2, type * 3)), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
}

void Ingame::Update()
{
	if (Player::coloring_per >= 80)
	{
		switch (type)
		{
		case 1:
			SCENE->Set("stage2");
			break;
		case 2:
			SCENE->Set("stage3");
			break;
		case 3:
			SCENE->Set("clear");
		}
	}
}

void Ingame::Render()
{
	if (INPUT->AnyDown() && !isReady)
	{
		isReady = true;
		Init();
	}
	
	switch (type)
	{
		case 1:
			tempbg = IMG->Find("before_bg1");
			Start  = IMG->Find("delayimg");
			tempbg->Render();
			Start->Render();
		break;
		case 2:
			tempbg = IMG->Find("Main");
			Start  = IMG->Find("delayimg");
			tempbg->Render();
			Start->Render();
		break;
		case 3:
			tempbg = IMG->Find("before_bg1");
			Start  = IMG->Find("delayimg");
			tempbg->Render();
			Start->Render();
		break;
	}
}

void Ingame::Release()
{
}
