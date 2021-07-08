#include "DXUT.h"
#include "Ingame.h"

Ingame::Ingame(int type)
	: type(type) // 초기화
{
}

void Ingame::Init()
{
	SOUND->Add("bgmusic", L"bgmusic")->Reset();
	CAM->Apply();
	type = VMGR->stage;
	isReady = VMGR->isReady;
	
	if (!isReady)
		return;
	SOUND->Add("bgmusic", L"bgmusic")->Play(true, VMGR->v_back, 0, 0);
	OBJ->Add(new Mouse, "Mouse"); // 마우스 오브젝트 생성

	switch (type) // type에 따른 스테이지 설정
	{
	case 1:
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER; // 보스 생성
		OBJ->Add(new Player(1), "player")->pos = { CENTER.x, float(B) }; // 플레이어 생성

		VMGR->stage = 1;
		enemy_count = 3;

		for (size_t i = 1; i <= enemy_count; i++)
			OBJ->Add(new Enemy(i), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
		break;
	case 2:
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER;
		OBJ->Add(new Player(2), "player")->pos = { CENTER.x, float(B) }; // 플레이어 생성

		VMGR->stage = 2;
		enemy_count = 3;

		for (size_t i = 1; i <= enemy_count; i++)
			OBJ->Add(new Enemy(i), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
		break;
	case 3:
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER;
		OBJ->Add(new Player(3), "player")->pos = { CENTER.x, float(B) }; // 플레이어 생성

		VMGR->stage = 3;
		enemy_count = 3;

		for (size_t i = 1; i <= enemy_count; i++)
			OBJ->Add(new Enemy(i), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
		break;
	}
}

void Ingame::Update()
{
	if (VMGR->hp <= 0 || Player::coloring_per >= 80)
	{
		SOUND->Add("bgmusic", L"bgmusic")->Stop();
	}
}

void Ingame::Render()
{
	if (INPUT->AnyDown() && !isReady)
	{
		VMGR->isReady = true;
		Init();
	}
	
	switch (type)
	{
		case 1:
			tempbg = IMG->Find("before1");
			Start  = IMG->Find("delayimg");
			tempbg->Render();
			Start->Render();
		break;
		case 2:
			tempbg = IMG->Find("before1");
			Start  = IMG->Find("delayimg");
			tempbg->Render();
			Start->Render();
		break;
		case 3:
			tempbg = IMG->Find("before1");
			Start  = IMG->Find("delayimg");
			tempbg->Render();
			Start->Render();
		break;
	}
}

void Ingame::Release()
{
}
