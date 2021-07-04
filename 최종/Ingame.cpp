#include "DXUT.h"
#include "Ingame.h"

Ingame::Ingame(int type)
	: type(type) // �ʱ�ȭ
{
}

void Ingame::Init()
{
	CAM->Apply();
	type = VMGR->stage;
	
	if (!isReady)
		return;

	OBJ->Add(new Mouse, "Mouse"); // ���콺 ������Ʈ ����

	switch (type) // type�� ���� �������� ����
	{
	case 1:
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER; // ���� ����
		enemy_count = 3;
		OBJ->Add(new Player(1), "player")->pos = { CENTER.x, float(B) }; // �÷��̾� ����

		for (size_t i = 0; i < enemy_count; i++)
			OBJ->Add(new Enemy(RANDOM->INT(1, 3)), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
		break;
	case 2:
		VMGR->stage = 2;
		enemy_count = 5;
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER;
		OBJ->Add(new Player(2), "player")->pos = { CENTER.x, float(B) }; // �÷��̾� ����

		for (size_t i = 0; i < enemy_count; i++)
			OBJ->Add(new Enemy(RANDOM->INT(1, 3)), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
		break;
	case 3:
		VMGR->stage = 3;
		enemy_count = 10;
		OBJ->Add(new Enemy(4), "boss")->pos = CENTER;
		OBJ->Add(new Player(3), "player")->pos = { CENTER.x, float(B) }; // �÷��̾� ����

		for (size_t i = 0; i < enemy_count; i++)
			OBJ->Add(new Enemy(RANDOM->INT(1, 3)), "Enemy")->pos = { float(RANDOM->INT(L + 1, R - 1)), float(RANDOM->INT(T + 1, B - 1)) };
		break;
	}
}

void Ingame::Update()
{
	if (Player::coloring_per >= 80)
	{
		switch (type)
		{
		case 1:
			VMGR->isWin = true;
			isReady = false;
			Player::coloring_per = 0;
			SCENE->Set("stage1_clear");
			break;
		case 2:
			VMGR->isWin = true;
			isReady = false;
			Player::coloring_per = 0;
			SCENE->Set("stage2_clear");
			break;
		case 3:
			VMGR->isWin = true;
			isReady = false;
			Player::coloring_per = 0;
			SCENE->Set("stage3_clear");
			break;
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
