#include "DXUT.h"
#include "Bullet.h"

Bullet::Bullet(int type, V2 dir)
	:type(type), dir(dir), speed(0)
{
}

void Bullet::Init()
{
	switch (type)
	{
	case 1:
		img = IMG->Add("player", "player");
		speed = 2;
		break;
	}
	main_col = new Col(this, EATK);
	delay = TIME->Create(0.5f);
	delay->Start();
}

void Bullet::Update()
{
	pos += dir * speed;

	if (delay->IsStop())
	{
		fxs.emplace_back(new Effect(img, pos, rot, 3));
		delay->Start();
	}

	main_col->Set(pos, 20, 20);

	POINT c = { trunc(pos.x), trunc(pos.y) };

	if (Player::cell[int(c.x)][int(c.y)] == 3)
		flag = true;

	if (pos.x < L || R < pos.x || pos.y < T || B < pos.y)
		flag = true;
}

void Bullet::Render()
{
	for (auto& i : fxs)
		i->Render();
	img->Render(pos, { 0,0,0,0 }, { 1,1 }, 0, 0, D3DCOLOR_RGBA(255, 0, 0, 255));
}

void Bullet::Release()
{
	SAFE_DELETE(main_col);
	for (auto& i : fxs)
		SAFE_DELETE(i);
	fxs.clear();
}

void Bullet::Enter(Col* p)
{
}

void Bullet::Stay(Col* p)
{
}

void Bullet::Exit(Col* p)
{
}
