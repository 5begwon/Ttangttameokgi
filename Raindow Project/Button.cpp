#include "DXUT.h"
#include "Button.h"

Button::Button(Texture* bg, V2 pos, const string& text, float w, float h, float depth, function<void()> func)
	:bg(bg), text(text), func(func), depth(depth), isOn(true)
{
	this->pos = pos;

	main_col = new Col(this, UI);
	main_col->Set(pos, w, h);

	OBJ->Add(this, "Button");
}
/*마우스 갖다 댔을때 - 색 생김
눌렀을떄 - 어둡고 작아짐
아무것도 안했을떄  (커서가 위에 올라가 있는것도 안됨 ) - 지금 리소스 (하양*/
void Button::On()
{
	isOn = true;
	//main_col->flag = true;
}

void Button::Off()
{
	isOn = false;
	isOver = false;
	//main_col->flag = false;
}

void Button::Init()
{
	isOver = false;	

	r = 255;
	g = 255;
	b = 255;
}

void Button::Update()
{
	if (isOver)
	{
		r = 155;
		g = 155;
		b = 155;
	}
	else
	{
		r = 255;
		g = 255;
		b = 255;
	}
}

void Button::Render()
{
	if (isOn)
	{
		bg->Render(pos, RT_ZERO, { 1,1 }, 0, depth, D3DCOLOR_RGBA(r, g, b, 255));
		IMG->Write(text, pos);
		//main_col->Draw();
	}
}

void Button::Release()
{
	SAFE_DELETE(main_col);
}

void Button::Enter(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			isOver = true;

			break;
		}
}

void Button::Stay(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			if (INPUT->Up(VK_LBUTTON))
				func();
				break;
		}
}

void Button::Exit(Col* p)
{
	if (isOn)
		switch (p->tag)
		{
		case MOUSE:
			isOver = false;

			break;
		}
}
