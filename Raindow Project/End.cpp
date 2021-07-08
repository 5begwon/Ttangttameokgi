#include "DXUT.h"
#include "End.h"

End::End(int type, bool isWin)
	:type(type), isWin(isWin)
{
}

void End::Init()
{
	OBJ->Add(new Mouse, "Mouse");    

	stage_c = IMG->Find("clear");
	stage_f = IMG->Find("fail");

	bg_c = IMG->Find("after_bg1");
	bg_f = IMG->Find("before1");

	type = VMGR->stage;
	isWin = VMGR->isWin;

	switch (type)
	{
		case 1:
		if (isWin == true)
		{
			next = new Button(IMG->Find("clear_next"), { CENTER.x - 323, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("stage2"), VMGR->stage = 2, Player::coloring_per = 0, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); });
			main = new Button(IMG->Find("clear_main"), { CENTER.x + 358, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("Title"), Player::coloring_per = 0, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0), SOUND->Add("bgmusic", L"bgmusic")->Stop(); });
		}
		if (isWin == false)
		{
			next = new Button(IMG->Find("fail_restart"), { CENTER.x - 323, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("stage1"), VMGR->stage = 1, Player::coloring_per = 0, VMGR->isReady = false, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0), SOUND->Add("bgmusic", L"bgmusic")->Stop(), SOUND->Add("bgmusic", L"bgmusic")->Play(true, VMGR->v_back, 0, 0); });
			main = new Button(IMG->Find("fail_main"),	 { CENTER.x + 358, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("Title"), Player::coloring_per = 0, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0), SOUND->Add("bgmusic", L"bgmusic")->Stop();  });
		}
		break;
		case 2:
		if (isWin == true)
		{
			next = new Button(IMG->Find("clear_next"), { CENTER.x - 323, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("stage3"), VMGR->stage = 3, Player::coloring_per = 0, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); });
			main = new Button(IMG->Find("clear_main"), { CENTER.x + 358, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("Title"), Player::coloring_per = 0, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0), SOUND->Add("bgmusic", L"bgmusic")->Stop();  });
		}
		if (isWin == false)
		{
			next = new Button(IMG->Find("fail_restart"), { CENTER.x - 323, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("stage2"), VMGR->stage = 2, Player::coloring_per = 0, VMGR->isReady = false, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); });
			main = new Button(IMG->Find("fail_main"),	 { CENTER.x + 358, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("Title"), Player::coloring_per = 0, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0), SOUND->Add("bgmusic", L"bgmusic")->Stop();  });
		}
		break;
		case 3:
		if (isWin == false)
		{
			next = new Button(IMG->Find("fail_restart"), { CENTER.x - 323, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("stage3"), VMGR->stage = 3, Player::coloring_per = 0, VMGR->isReady = false, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); });
			main = new Button(IMG->Find("fail_main"),	 { CENTER.x + 358, CENTER.y + 260 }, "", 348, 162, 1, [&]()->void { SCENE->Set("Title"), Player::coloring_per = 0, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0), SOUND->Add("bgmusic", L"bgmusic")->Stop(); });
		}
		break;
	}
}

void End::Update()
{
}

void End::Render()
{
	switch (type)
	{
		SOUND->Add("bgmusic", L"bgmusic")->Stop();
		case 1:
		if (isWin == true)
		{
			bg_c->Render(CENTER, RT_ZERO, { 1,1 }, 0, 1);
			stage_c->Render(CENTER, RT_ZERO, ONE, 0, 1);
			sprintf(str, "%02d%", (int)Player::coloring_per);
			IMG->Write(str, { CENTER.x - 100, CENTER.y - 10 }, 270);
		}
		if (isWin == false)
		{
			bg_f->Render(CENTER, RT_ZERO, { 1,1 }, 0, 1);
			stage_f->Render(CENTER, RT_ZERO, ONE, 0, 1);
			sprintf(str, "%02d%", (int)Player::coloring_per);
			IMG->Write(str, { CENTER.x - 100, CENTER.y - 10 }, 270);
		}
		break;
		case 2:
		if (isWin == true)
		{
			bg_c->Render(CENTER, RT_ZERO, { 1,1 }, 0, 1);
			stage_c->Render(CENTER, RT_ZERO, ONE, 0, 1);
			sprintf(str, "%02d%", (int)Player::coloring_per);
			IMG->Write(str, { CENTER.x - 100, CENTER.y - 10 }, 270);
		}
		if (isWin == false)
		{
			bg_f->Render(CENTER, RT_ZERO, { 1,1 }, 0, 1);
			stage_f->Render(CENTER, RT_ZERO, ONE, 0, 1);
			sprintf(str, "%02d%", (int)Player::coloring_per);
			IMG->Write(str, { CENTER.x - 100, CENTER.y - 10 }, 270);
		}
		break;
		case 3:
		if (isWin == true)
		{
			IMG->Find("credit")->Render(CENTER, RT_ZERO, ONE, 0, 0.8f, D3DCOLOR_ARGB(255, 255, 255, 255), true);
			if (INPUT->AnyDown())
			{
				SOUND->Add("bgmusic", L"bgmusic")->Stop();
				SCENE->Set("Title");
			}
		}
		if (isWin == false)
		{
			bg_f->Render(CENTER, RT_ZERO, { 1,1 }, 0, 1);
			stage_f->Render(CENTER, RT_ZERO, ONE, 0, 1);
			sprintf(str, "%02d%", (int)Player::coloring_per);
			IMG->Write(str, { CENTER.x - 100, CENTER.y - 10}, 270);
		}
		break;
	}
}

void End::Release()
{
}
