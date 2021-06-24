#include "DXUT.h"
#include "End.h"

End::End(int type, bool isWin)
	:type(type), isWin(isWin)
{
}

void End::winfalse()
{
	VMGR->isWin = false;
}

void End::Init()
{
	VMGR->isWin = isWin;

	OBJ->Add(new Mouse, "Mouse");    

	next = new Button(IMG->Find("BigBlue"), { CENTER.x - 300, CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("stage1"); });
	main = new Button(IMG->Find("BigBlue"), { CENTER.x + 300, CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("Title");  });

	stage_c = IMG->Find("clear");

	winfalse();
}

void End::Update()
{
	switch (type)
	{
		case 1:
		stage_c = IMG->Find("clear");
		break;
		case 2:
		stage_c = IMG->Find("Main");
		break;
		case 3:
		stage_c = IMG->Find("white");
		break;
	}
}

void End::Render()
{
	if (type == 1 && isWin == true)
	{
		stage_c->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
		IMG->Write("Congratulations on Clear!");
		winfalse();
	}
	else if (type == 1 && isWin == false)
	{
		stage_c->Render(CENTER, RT_ZERO, ONE, 0, 0.5f);
		IMG->Write("I wish you success next time...");
		winfalse();
	}

	if (type == 2 && isWin == true)
	{
		IMG->Write("Congratulations on Clear!");
		winfalse();
	}
	else if (type == 2 && isWin == false)
	{
		IMG->Write("I wish you success next time...");
		winfalse();
	}

	if (type == 3 && isWin == true)
	{
		IMG->Write("Congratulations on Clear!");
		winfalse();
	}
	else if (type == 3 && isWin == false)
	{
		IMG->Write("I wish you success next time...");
		winfalse();
	}
}

void End::Release()
{
}
