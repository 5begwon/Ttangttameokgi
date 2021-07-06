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

	type = VMGR->stage;
	isWin = VMGR->isWin;

	switch (type)
	{
		case 1:
		if(isWin == true)
		{
			next = new Button(IMG->Find("BigBlue"), { CENTER.x - 300, CENTER.y + 300 }, "Next", 440, 200, 1, [&]()->void { SCENE->Set("stage2"), VMGR->stage = 2; });
			main = new Button(IMG->Find("BigBlue"), { CENTER.x + 300, CENTER.y + 300 }, "Title", 440, 200, 1, [&]()->void { SCENE->Set("Title");  }); 
		}
		if (isWin == false)
		{
			next = new Button(IMG->Find("BigBlue"), { CENTER.x - 300, CENTER.y + 300 }, "Restart", 440, 200, 1, [&]()->void { SCENE->Set("stage1"), VMGR->stage = 1; });
			main = new Button(IMG->Find("BigBlue"), { CENTER.x + 300, CENTER.y + 300 }, "Title", 440, 200, 1, [&]()->void { SCENE->Set("Title");  });
		}
		break;
		case 2:
		if (isWin == true)
		{
			next = new Button(IMG->Find("BigBlue"), { CENTER.x - 300, CENTER.y + 300 }, "Next", 440, 200, 1, [&]()->void { SCENE->Set("stage3"), VMGR->stage = 3; });
			main = new Button(IMG->Find("BigBlue"), { CENTER.x + 300, CENTER.y + 300 }, "Title", 440, 200, 1, [&]()->void { SCENE->Set("Title");  });
		}
		if (isWin == false)
		{
			next = new Button(IMG->Find("BigBlue"), { CENTER.x - 300, CENTER.y + 300 }, "Restart", 440, 200, 1, [&]()->void { SCENE->Set("stage2"), VMGR->stage = 2; });
			main = new Button(IMG->Find("BigBlue"), { CENTER.x + 300, CENTER.y + 300 }, "Title", 440, 200, 1, [&]()->void { SCENE->Set("Title");  });
		}
		break;
		case 3:
		if (isWin == false)
		{
			next = new Button(IMG->Find("BigBlue"), { CENTER.x - 300, CENTER.y + 300 }, "Restart", 440, 200, 1, [&]()->void { SCENE->Set("stage3"), VMGR->stage = 3; });
			main = new Button(IMG->Find("BigBlue"), { CENTER.x + 300, CENTER.y + 300 }, "Title", 440, 200, 1, [&]()->void { SCENE->Set("Title");  });
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
		case 1:
		if (isWin == true)
		{
			stage_c->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
			sprintf(str, "%02d%%", (int)Player::coloring_per);
			IMG->Write(str, { CENTER.x, CENTER.y - 380 }, 120);
		}
		if (isWin == false)
		{
			stage_c->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
			IMG->Write("I wish you Stage 1 success next time...");
		}
		break;
		case 2:
		if (isWin == true)
		{
			stage_c->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
			IMG->Write("Congratulations on Stage 2 Clear!");
		}
		if (isWin == false)
		{
			stage_c->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
			IMG->Write("I wish you Stage 2 success next time...");
		}
		break;
		case 3:
		if (isWin == true)
		{
			IMG->Find("credit")->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
			if (INPUT->AnyDown())
			{
				SCENE->Set("Title");
			}
		}
		if (isWin == false)
		{
			stage_c->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
			IMG->Write("I wish you Stage 3 success next time...");
		}
		break;
	}
}

void End::Release()
{
}
