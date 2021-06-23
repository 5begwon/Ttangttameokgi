#include "DXUT.h"
#include "End.h"

End::End(int type, bool isWin)
	:type(type), isWin(isWin)
{
}

void End::Init()
{
	OBJ->Add(new Mouse, "Mouse");    

	next = new Button(IMG->Find("BigBlue"), { CENTER.x - 300, CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("stage1"); });
	main = new Button(IMG->Find("BigBlue"), { CENTER.x + 300, CENTER.y + 300 }, "", 440, 200, 1, [&]()->void { SCENE->Set("Title");  });

	stage1_c = IMG->Add("clear", "clear");
}

void End::Update()
{
}

void End::Render()
{
	if (type == 1 && isWin == true)
	{
		stage1_c->Render(CENTER, RT_ZERO, ONE, 0, 0);
		IMG->Write("Congratulations on Clear!");
	}
	else if (type == 1 && isWin == false)
	{
		IMG->Write("I wish you success next time...");
	}

	if (type == 2 && isWin == true)
	{
		IMG->Write("Congratulations on Clear!");
	}
	else if (type == 2 && isWin == false)
	{
		IMG->Write("I wish you success next time...");
	}

	if (type == 3 && isWin == true)
	{
		IMG->Write("Congratulations on Clear!");
	}
	else if (type == 3 && isWin == false)
	{
		IMG->Write("I wish you success next time...");
	}
}

void End::Release()
{
}
