#pragma once
#include "Scene.h"
class Ingame :
    public Scene
{
public:
    Ingame(int type); // int type = 스테이지(정수)

    Texture* tempbg;
    Texture* Start;

    bool isReady = false;

    int type;
    int enemy_count = 0; // 한 스테이지당 나올 몹 수

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

