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

	switch (type)
	{
		case 1:
			wait = TIME->Create(0.01f);
			wait->Start();
			break;
		case 2:
			howtoplay = new Button
			(
				IMG->Find("howto"),
				{ 291, CENTER.y + 168 },
				"",
				326,
				52,
				1,
				[&]()->void { howtoplay_window->On(); }
			);
			start = new Button
			(
				IMG->Find("start"),
				{ 282, CENTER.y + 245 },
				"",
				300,
				52,
				1,
				[&]()->void { SCENE->Set("Stage"); }
			);
			option = new Button
			(
				IMG->Find("option"),
				{ 225, CENTER.y + 325 },
				"",
				188,
				52,
				1,
				[&]()->void { option_window->On(); }
			);
			option_window	 = new Window(IMG->Find("option_window"), CENTER, 400, 600);
			howtoplay_window = new Window(IMG->Find("howtoplay_window"), CENTER, 600, 600);
			break;
		case 3:
		stage1 = new Button
		(
			IMG->Find("invisable"),
			{ CENTER.x +  200, CENTER.y + 50 },
			"",
			120,
			120,
			1,
			[&]()->void { SCENE->Set("stage1"), VMGR->stage = 1; }
		);
		stage2 = new Button
		(
			IMG->Find("invisable"),
			{ CENTER.x + 200, CENTER.y + 200 },
			"",
			120,
			120,
			1,
			[&]()->void { SCENE->Set("stage2"), VMGR->stage = 2; }
		);
		stage3 = new Button
		(
			IMG->Find("invisable"),
			{ CENTER.x + 200, CENTER.y + 350 },
			"",
			120,
			120,
			1,
			[&]()->void { SCENE->Set("stage3"), VMGR->stage = 3; }
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