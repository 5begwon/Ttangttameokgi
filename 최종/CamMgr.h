#pragma once
class Timer;
class CamMgr :
	public st<CamMgr>
{
public:
	CamMgr();
	~CamMgr() { ; };

	void Update();
	void Reset();
	void Apply();
	void Shake(float time, float force);

	Timer* shake_timer;
	float shake_force;

	float rot;
	M pro, view;
	V2 pos, size;
	V3 scale;
};

#define CAM CamMgr::G()