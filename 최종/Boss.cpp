#include "DXUT.h"
#include "Boss.h"

Boss::Boss(int type)
	:type(type)
{
}

void Boss::Flash()
{
	dir = RANDOM->Vec2(pos);

	fxs.emplace_back(new Effect(img, pos, 0, 4));

	pos += dir * 50;
}

void Boss::Rush()
{
	during->Start();
	char str[256];
	sprintf(str, "enemy%d_red", type);
	img = IMG->Add(str, str);
}

void Boss::Shot(int shots)
{
	int angle = 360 / shots;
	for (int i = 0; i < 360; i += angle)
		OBJ->Add(new Bullet(1, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;
}

void Boss::Init()
{
	b_ani = vector<Texture*>
	{
		IMG->Add("boss1", "boss1"),
		IMG->Add("boss2", "boss2"),
		IMG->Add("boss3", "boss3"),
		IMG->Add("boss4", "boss4"),
		IMG->Add("boss5", "boss5"),
		IMG->Add("boss6", "boss6"),
		IMG->Add("boss7", "boss7"),
		IMG->Add("boss8", "boss8"),
		IMG->Add("boss9", "boss9"),
		IMG->Add("boss10", "boss10"),
		IMG->Add("boss11", "boss11"),
		IMG->Add("boss12", "boss12"),
	};

	dir = RANDOM->Vec2(pos);
	char str[256];
	sprintf(str, "enemy%d", type);
	img = IMG->Add(str, str);
	cool = 0;
	speed = 0;
	size = { 1,1 };
	rot = 0;
	spin_force = 0;
	main_col = new Col(this, EATK);

	switch (type)
	{
		case 1:
		cool = 5;
		size = sizes[0];
		speed = speeds[0];
		break;
		case 2:
		cool = 5;
		size = sizes[0];
		speed = speeds[1];
		break;
		case 3:
		cool = 5;
		size = sizes[0];
		speed = speeds[2];
		break;
		case 4:
		cool = 10;
		size = sizes[1];
		speed = speeds[3];
		break;
	}

	timer = TIME->Create(cool);
	timer->Start();
	during = TIME->Create(3);
}

void Boss::Update()
{
	for (int i = 0; i < speed * VMGR->time_scale * DT; i++)
	{
		pos += dir;
	}

	//spin_force += DT * 100;
	//if (spin_force >= 360)
	//	spin_force = 0;
	//
	int range = 7;

	switch (type)
	{
		//	case 1:
			//case 4:
			//	if (timer->IsStop())
			//	{
		//	//		Flash();
			//		timer->Start();
			//	}
			//	break;
			//case 7:
			//	range = 110;
			//	if (timer->IsStop())
			//	{
		//	//		Rush();
			//		timer->Start();
			//	}
			//	if (during->IsStop())
			//	{
			//		char str[256];
			//		sprintf(str, "enemy%d", type);
			//		img = IMG->Add(str, str);
			//	}
			//	else
			//	{
			//		pos += dir * 10;
			//		fxs.emplace_back(new Effect(img, pos, rot, 3));
			//	}
			//	break;
			//case 8:
			//	range = 110;
			//	if (timer->IsStop())
			//	{
			//		Shot(36);
			//		timer->Start(); 
			//	}
			//	break;
	}

	main_col->Set(pos, 16 * size.x, 16 * size.y);

	POINT c = { trunc(pos.x) - gap.x, trunc(pos.y) - gap.y };

	for (int y = -range; y <= range; y++)
		for (int x = -range; x <= range; x++)
			if (Player::cell[c.x + x][c.y + y] == 2)
				dir = RANDOM->Vec2(pos);

	if (Player::cell[c.x][c.y] == 3)
		if (type < 7)
			flag = true;
}

void Boss::Render()
{
	main_col->Draw();
	for (auto& i : fxs)
		i->Render();
	img->Render(pos, { 0,0,0,0 }, { 1,1 }, D3DXToRadian(rot), 0.5f);
}

void Boss::Release()
{
	SAFE_DELETE(main_col);
	for (auto& i : fxs)
		SAFE_DELETE(i);
	fxs.clear();
}

void Boss::Enter(Col* p)
{
}

void Boss::Stay(Col* p)
{
}

void Boss::Exit(Col* p)
{
}
