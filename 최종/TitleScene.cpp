#include "DXUT.h"
#include "TitleScene.h"

TitleScene::TitleScene(int type)
	:type(type)
{
}

void TitleScene::Init()
{
	CAM->pos = CENTER;
	alpha = 255;
	OBJ->Add(new Mouse, "Mouse");

	white = IMG->Add("white", "white");
	logo = IMG->Add("logo", "logo");
	bg = IMG->Add("Main", "Main");
	select = IMG->Add("stage", "stage");

	switch (type)
	{
		case 1:
			wait = TIME->Create(0.01f);
			wait->Start();
			break;
		case 2:
		howtoplay = new Button
		(
			IMG->Add("howto", "howto"),
			{ 291, CENTER.y + 168 },
			"",
			326,
			52,
			1,
			[&]()->void { howtoplay_window->On(); }
		);
		start = new Button
		(
			IMG->Add("start", "start"),
			{ 282, CENTER.y + 245 },
			"",
			300,
			52,
			1,
			[&]()->void {SCENE->Set("Stage"); }
		);
		option = new Button
		(
			IMG->Add("option", "option"),
			{ 225, CENTER.y + 325 },
			"",
			188,
			52,
			1,
			[&]()->void {option_window->On(); }
		);
		option_window = new Window(IMG->Add("option_window", "option_window"), CENTER, 400, 600);
		howtoplay_window = new Window(IMG->Add("howtoplay_window", "howtoplay_window"), CENTER, 600, 600);
		break;
		case 3:
		stage1 = new Button
		(
			IMG->Add("invisable", "invisable"),
			{ CENTER.x +  200, CENTER.y + 50 },
			"",
			120,
			120,
			1,
			[&]()->void { SCENE->Set("stage1"); }
		);
		stage2 = new Button
		(
			IMG->Add("invisable", "invisable"),
			{ CENTER.x + 200, CENTER.y + 200 },
			"",
			120,
			120,
			1,
			[&]()->void { SCENE->Set("stage2"); }
		);
		stage3 = new Button
		(
			IMG->Add("invisable", "invisable"),
			{ CENTER.x + 200, CENTER.y + 350 },
			"",
			120,
			120,
			1,
			[&]()->void { SCENE->Set("stage3"); }
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
			alpha = alpha < 0 ? 0 : alpha - 1;
			wait->Start();
		}
		if (alpha == 0 || INPUT->AnyDown()) SCENE->Set("Title");
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
			logo->Render(CENTER, RT_ZERO, V2(1, 1), 0, 1, D3DCOLOR_RGBA(255, 255, 255, alpha), true);
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