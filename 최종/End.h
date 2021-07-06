#pragma once
#include "Scene.h"
class End :
    public Scene
{
public:
    End(int type, bool isWin);

    Texture* stage_c;
    Texture* stage_f;

    Button* main;
    Button* next;

    int type;
    bool isWin;

    char str[256];

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

