#pragma once
struct Sound
{
	CSound* p;
	Sound(CSound* p)
		:p(p) {}
	~Sound() { SAFE_DELETE(p); }

	void Play(bool loop);
	void Copy();
	void Stop();
	Sound* SetVolume(LONG volume);
	Sound* SetPan(LONG pan);
};
class SoundMgr :
	public st<SoundMgr>
{ 
public:
	SoundMgr();
	~SoundMgr();

	Sound* Add(const string& key, const wstring& path);
	Sound* Find(const string& key);

	void Play(Sound* p, bool loop);
	void Copy(Sound* p);
	void Stop(Sound* p);
	Sound* SetVolume(Sound* p, LONG volume);
	Sound* SetPan(Sound* p, LONG pan);

	map<string, Sound*> sounds;
	CSoundManager* mgr;
};

#define SOUND SoundMgr::G()