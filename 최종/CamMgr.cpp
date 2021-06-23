#include "DXUT.h"
#include "CamMgr.h"

CamMgr::CamMgr()
{
	Reset();

	D3DXMatrixOrthoLH(&pro, size.x, -size.y, 0, 1);
}

void CamMgr::Update()
{
	M mRot, mScale, mPos;
	D3DXMatrixTranslation(&mPos, -pos.x, -pos.y, 0); //(&mPos, -pos.x * scale.x, -pos.y * scale.y, 0);
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixRotationZ(&mRot, D3DXToRadian(rot));

	view = mRot * mScale * mPos;
}

void CamMgr::Reset()
{
	pos = CENTER;
	size = { WINX,WINY };
	scale = { 1,1,1 };
}

void CamMgr::Apply()
{
	DEVICE->SetTransform(D3DTS_VIEW, &view);
	DEVICE->SetTransform(D3DTS_PROJECTION, &pro);
}
