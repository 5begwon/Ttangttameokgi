#include "DXUT.h"
#include "MainGame.h"

void MainGame::Init()
{
	CAM->Reset();

	AddResource();

	SCENE->Add(new TitleScene(1), "Intro");
	SCENE->Add(new TitleScene(2), "Title");
	SCENE->Add(new TitleScene(3), "Stage");

	SCENE->Add(new Ingame(1), "stage1");
	SCENE->Add(new Ingame(2), "stage2");
	SCENE->Add(new Ingame(3), "stage3");

	SCENE->Add(new End(1, true), "stage1_clear");
	SCENE->Add(new End(1, false), "stage1_fail");
	SCENE->Add(new End(2, true), "stage2_clear");
	SCENE->Add(new End(2, false), "stage2_fail");	
	SCENE->Add(new End(3, true), "stage3_clear");
	SCENE->Add(new End(3, false), "stage3_fail");
	SCENE->Set("Intro");
}

void MainGame::Update()
{
	INPUT->Update();
	TIME->Update();
	CAM->Update();
	SCENE->Update();
	OBJ->Update();
	HOT->Update();
}

void MainGame::Render()
{
	CAM->Apply();

	IMG->Begin();
	SCENE->Render();
	OBJ->Render();
	IMG->End();
}

void MainGame::Release()
{
	CamMgr::D();
	ImgMgr::D();
	ObjMgr::D();
	HotKey::D();
	TimeMgr::D();
	SceneMgr::D();
	SoundMgr::D();
	InputMgr::D();
	RandomMgr::D();
}

void MainGame::Lost()
{
	IMG->Lost();
}

void MainGame::Reset()
{
	IMG->Reset();
}

void MainGame::AddResource()
{
	// OBJ
	IMG->Add("player", "player");

	// UI
	IMG->Add("logo", "logo");
	IMG->Add("rainbow", "rainbow");
	IMG->Add("pause", "pause");
	IMG->Add("button_cross", "button_cross");
	IMG->Add("howto", "howto");
	IMG->Add("start", "start");
	IMG->Add("option", "option");
	IMG->Add("option_window", "option_window");
	IMG->Add("howtoplay_window", "howtoplay_window");
	IMG->Add("invisable", "invisable");

	// BG
	IMG->Add("white", "white");
	IMG->Add("stage", "stage");
	IMG->Add("Main", "Main");
	IMG->Add("after_bg1", "after_bg1");
	IMG->Add("before_bg1", "before_bg1");
	IMG->Add("delayimg", "delayimg");
	IMG->Add("clear", "clear");
}
