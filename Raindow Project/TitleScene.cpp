#include "DXUT.h"
#include "TitleScene.h"

TitleScene::TitleScene(int type)
	:type(type)
{
}

void TitleScene::Init()
{
	alpha = 255.0f;
	OBJ->Add(new Mouse, "Mouse");

	white  = IMG->Find("white");
	logo   = IMG->Find("logo");
	bg	   = IMG->Find("Main");
	select = IMG->Find("stage");

	dog_sound = SOUND->Add("dog", L"dog");

	wait = TIME->Create(0.01f);
	wait->Start();

	switch (type)
	{
		case 1:
		dog_sound->Play(false, VMGR->v_effect, 0, 0);
		break;
		case 2:
			SOUND->Add("title", L"title")->Reset();

			howtoplay = new Button
			(
				IMG->Find("howto"),
				{ 291, CENTER.y + 168 },
				"",
				326,
				52,
				1,
				[&]()->void { howtoplay_window->On(), SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
			);
			start = new Button
			(
				IMG->Find("start"),
				{ 282, CENTER.y + 245 },
				"",
				300,
				52,
				1,
				[&]()->void { SCENE->Set("Stage"), SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
			);
			option = new Button
			(
				IMG->Find("option"),
				{ 225, CENTER.y + 325 },
				"",
				188,
				52,
				1,
				[&]()->void { option_window->On(), SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
			);
			howtoplay_window = new Window(IMG->Find("howtoplay_window"), CENTER, 600, 600);
			option_window = new Window(IMG->Find("option_window"), CENTER, 600, 600);
			if (backv == BON)
			{
				b_sound_on = new Button
				(
					IMG->Find("b_sound_on_on"),
					{ CENTER.x - 500, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { backv = BON, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
				b_sound_off = new Button
				(
					IMG->Find("b_sound_off_off"),
					{ CENTER.x - 200, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { backv = BOFF, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
			}
			if (backv == BOFF)
			{
				b_sound_on = new Button
				(
					IMG->Find("b_sound_on_off"),
					{ CENTER.x - 500, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { backv = BON, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
				b_sound_off = new Button
				(
					IMG->Find("b_sound_off_on"),
					{ CENTER.x - 200, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { backv = BOFF, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
			}
			if (effectv == EON)
			{
				e_sound_on = new Button
				(
					IMG->Find("e_sound_on_on"),
					{ CENTER.x + 230, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { effectv = EON, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
				e_sound_off = new Button
				(
					IMG->Find("e_sound_off_off"),
					{ CENTER.x + 530, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { effectv = EOFF, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
			}
			if (effectv == EOFF)
			{
				e_sound_on = new Button
				(
					IMG->Find("e_sound_on_off"),
					{ CENTER.x + 230, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { effectv = EON, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
				e_sound_off = new Button
				(
					IMG->Find("e_sound_off_on"),
					{ CENTER.x + 530, CENTER.y + 30 },
					"",
					220,
					220,
					0.8f,
					[&]()->void { effectv = EOFF, SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
				);
			}
			break;
		case 3:
		stage1 = new Button
		(
			IMG->Find("stage1"),
			{ CENTER.x + 2, CENTER.y - 106 },
			"",
			1158,
			54,
			1,
			[&]()->void { SCENE->Set("stage1"), VMGR->stage = 1, SOUND->Add("title", L"title")->Stop(), SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
		);
		stage2 = new Button
		(
			IMG->Find("stage2"),
			{ CENTER.x - 12, CENTER.y + 20 },
			"",
			822,
			54,
			1,
			[&]()->void { SCENE->Set("stage2"), VMGR->stage = 2, SOUND->Add("title", L"title")->Stop(), SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
		);
		stage3 = new Button
		(
			IMG->Find("stage3"),
			{ CENTER.x - 5, CENTER.y + 145 },
			"",
			870,
			54,
			1,
			[&]()->void { SCENE->Set("stage3"), VMGR->stage = 3, SOUND->Add("title", L"title")->Stop(), SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
		);

		title = new Button
		(
			IMG->Find("button_cross"),
			{ CENTER.x, CENTER.y + 280 },
			"",
			121,
			121,
			1,
			[&]()->void { SCENE->Set("Title"), SOUND->Add("click", L"click")->Play(false, VMGR->v_effect, 0, 0); }
		);
		break;
	}
}

void TitleScene::Update()
{
	switch (type)
	{
		case 1:
		if (wait->IsStop())
		{
			alpha = alpha < 0 ? 0 : alpha - 1.5f;
			wait->Start();
		}
		if (alpha <= 0 ) SCENE->Set("Title");
		break;
		case 2:
		SOUND->Add("title", L"title")->Play(true, VMGR->v_back, 0, 0);
		if (option_window->isOn == true)
		{
			e_sound_off->On();
			e_sound_on->On();
			b_sound_off->On();
			b_sound_on->On();
		}
		else
		{
			e_sound_off->Off();
			e_sound_on->Off();
			b_sound_off->Off();
			b_sound_on->Off();
		}
		if (backv == BON)
		{
			b_sound_on->bg = IMG->Find("b_sound_on_on");
			b_sound_off->bg = IMG->Find("b_sound_off_off");

			VMGR->v_back = 0;
		}
		if (backv == BOFF)
		{
			b_sound_on->bg = IMG->Find("b_sound_on_off");
			b_sound_off->bg = IMG->Find("b_sound_off_on");

			VMGR->v_back = -10000;
		}
		if (effectv == EON)
		{
			e_sound_on->bg = IMG->Find("e_sound_on_on");
			e_sound_off->bg = IMG->Find("e_sound_off_off");

			VMGR->v_effect = 0;
		}
		if(effectv == EOFF)
		{
			e_sound_on->bg = IMG->Find("e_sound_on_off");
			e_sound_off->bg = IMG->Find("e_sound_off_on");

			VMGR->v_effect = -10000;
		}
		break;
		case 3:
		break;
	}
}

void TitleScene::Render()
{
	switch (type)
	{
		case 1:
			white->Render();
			logo->Render(CENTER, RT_ZERO, V2(1, 1), 0, 1, D3DCOLOR_RGBA(255, 255, 255, (int)alpha), true);
		break;
		case 2:
			bg->Render(CENTER, RT_ZERO, V2(1, 1), 0, 1, D3DCOLOR_RGBA(255, 255, 255, 255), true);
			break;
		case 3:
			select->Render(CENTER, RT_ZERO, V2(1, 1), 0, 1, D3DCOLOR_RGBA(255, 255, 255, 255), true);
		break;
	}
}

void TitleScene::Release()
{
}