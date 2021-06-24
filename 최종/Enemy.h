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
        {12.65f, 12.65f}, // ���� ������
        {22, 22},         // �� ������
    };

    vector<float> speeds = vector<float>
    {
        1.5f,   // ���� ���ǵ�
        2.0f,   // �� ���ǵ�
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

