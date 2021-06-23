#include "DXUT.h"
#include "MainGame.h"

void MainGame::Init()
{
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
