#pragma once
#include "Obj.h"
class Enemy :
    public Obj
{
public:
    Enemy(int type);

    vector<Effect*> fxs;

    Texture* img;
    Timer* timer;
    Timer* during;
    V2 size;
    V2 dir;

    float cool;
    float rot;
    int type;
    int spin_force;

    vector<V2> sizes = vector<V2>
    {
        {7, 7},    // �� ������
        {16, 16}, // ���� ������
    };

    vector<float> speeds = vector<float>
    {
        400,   // �� ���ǵ�
        300,   // �� ���ǵ�
        200,   // �� ���ǵ�
        250,   // ���� ���ǵ�
        0.0f,
    };

    void Flash();
    void Rush();
    void Shot(int shots);

    // Obj��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

