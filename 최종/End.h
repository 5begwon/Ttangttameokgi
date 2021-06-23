#pragma once
#include "Scene.h"
class End :
    public Scene
{
public:
    End(int type, bool isWin);

    Texture* stage1_c;
    Texture* stage1_f;
    Texture* stage2_c;
    Texture* stage2_f;
    Texture* stage3_c;
    Texture* stage3_f;

    Button* main;
    Button* next;

    int type;
    bool isWin = false;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

