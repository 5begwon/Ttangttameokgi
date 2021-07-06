#include "DXUT.h"
#include "Enemy.h"

Enemy::Enemy(int type)
	:type(type)
{
}

void Enemy::Flash()
{
	dir = RANDOM->Vec2(pos);

	fxs.emplace_back(new Effect(img, pos, 0, 4));

	pos += dir * 50;
}

void Enemy::Rush()
{
	during->Start();
	char str[256];
	sprintf(str, "enemy%d_red", type);
	img = IMG->Add(str, str);
}

void Enemy::Shot(int shots)
{
	int angle = 360 / shots;
	for (int i = 0; i < 360; i += angle)
		OBJ->Add(new Bullet(1, { cos(D3DXToRadian(i)), sin(D3DXToRadian(i)) }), "Bullet")->pos = pos;
}

void Enemy::Init()
{	
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
	ANIM->Add("boss", "boss", "")->Start();

	timer = TIME->Create(cool);
	timer->Start();
	during = TIME->Create(3.0f);
}

void Enemy::Update()
{
	for (int i = 0; i < speed * VMGR->time_scale; i++)
	{
		pos += dir;

		if (pos.x < L)
			RANDOM->Reflex(&dir, V2(-1, 0));
		if (pos.x > R)
			RANDOM->Reflex(&dir, V2(1, 0));
		if (pos.y < T)
			RANDOM->Reflex(&dir, V2(0, -1));
		if (pos.y > B)
			RANDOM->Reflex(&dir, V2(0, 1));

		if (Player::cell[int(pos.x) + 1][int(pos.y)] == 2)
			RANDOM->Reflex(&dir, V2(1, 0));
		if (Player::cell[int(pos.x) - 1][int(pos.y)] == 2)
			RANDOM->Reflex(&dir, V2(-1, 0));
		if (Player::cell[int(pos.x)][int(pos.y) + 1] == 2)
			RANDOM->Reflex(&dir, V2(0, 1));
		if (Player::cell[int(pos.x)][int(pos.y) - 1] == 2)
			RANDOM->Reflex(&dir, V2(0, -1));
	}

	spin_force += DT * 100;
	if (spin_force >= 360)
		spin_force = 0;
	
	int range = 7;

	//switch (type)
	//{
	//	case 4:
	//		//range = 110;
	//		if (timer->IsStop())
	//		{
	//			speed = speeds[5];
	//			timer->Start();
	//		}
	//}

	main_col->Set(pos, 16 * size.x, 16 * size.y);

	POINT c = { trunc(pos.x) - gap.x, trunc(pos.y) - gap.y };

	for (int y = -range; y <= range; y++)
		for (int x = -range; x <= range; x++)
			if (Player::cell[c.x + x][c.y + y] == 2)
				dir = RANDOM->Vec2(pos);

	if (Player::cell[c.x][c.y] == 3)
		if (type <= 4)
			flag = true;
}

void Enemy::Render()
{
	main_col->Draw();
	for (auto& i : fxs)
		i->Render();

	switch (type)
	{
		case 4:
		img = ANIM->Add("boss", "boss", "")->CurText;
		break;
	}

	//rot += spin_force;
	//if (rot >= 360)
	//	rot = 0;
	img->Render(pos, { 0,0,0,0 }, { 1,1 }, D3DXToRadian(rot), 0.5f);
}

void Enemy::Release()
{
	SAFE_DELETE(main_col);
	for (auto& i : fxs)
		SAFE_DELETE(i);
	fxs.clear();
}

void Enemy::Enter(Col* p)
{
}

void Enemy::Stay(Col* p)
{
}

void Enemy::Exit(Col* p)
{
}
