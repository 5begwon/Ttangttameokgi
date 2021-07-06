#pragma once
#include "Obj.h"
class Boss :
    public Obj
{
public:
    Boss(int type);

    vector<Effect*> fxs;
    vector<Texture*> b_ani;

    Texture* img;
    Timer* timer;
    Timer* delay;
    Timer* during;
    V2 size;
    V2 dir;

    float cool;
    float rot;
    int type;
    int spin_force;

    vector<V2> sizes = vector<V2>
    {
        {8, 8},         // �� ������
        {18, 18}, // ���� ������
    };

    vector<float> speeds = vector<float>
    {
        3.0f,   // �� ���ǵ�
        2.5f,   // �� ���ǵ�
        2.0f,   // �� ���ǵ�
        1.5f,   // ���� ���ǵ�
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

