#pragma once
#include "Scene.h"
class Ingame :
    public Scene
{
public:
    Ingame(int type); // int type = ��������(����)

    Texture* tempbg;
    Texture* Start;

    bool isReady = false;

    int type;
    int enemy_count = 0; // �� ���������� ���� �� ��

    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

