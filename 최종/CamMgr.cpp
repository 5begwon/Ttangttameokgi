#include "DXUT.h"
#include "CamMgr.h"

CamMgr::CamMgr()
{
	Reset();

	D3DXMatrixOrthoLH(&pro, size.x, -size.y, 0, 1);

	shake_timer = TIME->Create(0);

}

void CamMgr::Update()
{
	if (!shake_timer->IsStop())
	{
		pos.x += float(RANDOM->INT(-shake_force, shake_force));
		pos.y += float(RANDOM->INT(-shake_force, shake_force));
	}
	M mRot, mScale, mPos;
	D3DXMatrixTranslation(&mPos, -pos.x, -pos.y, 0);
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(rot));

	view = mRot * mScale * mPos;

	CAM->pos = CENTER;
}

void CamMgr::Reset()
{
	rot = 0;
	pos = CENTER;
	size = { WINX, WINY };
	scale = { 1, 1, 1 };
}

void CamMgr::Apply()
{
	DEVICE->SetTransform(D3DTS_VIEW, &view);
	DEVICE->SetTransform(D3DTS_PROJECTION, &pro);
}

void CamMgr::Shake(float time, float force)
{
	shake_timer = TIME->Create(time);
	shake_timer->Start();
	shake_force = force;
}
