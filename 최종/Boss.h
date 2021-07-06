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
        {8, 8},         // 몹 사이즈
        {18, 18}, // 보스 사이즈
    };

    vector<float> speeds = vector<float>
    {
        3.0f,   // 몹 스피드
        2.5f,   // 몹 스피드
        2.0f,   // 몹 스피드
        1.5f,   // 보스 스피드
    };

    void Flash();
    void Rush();
    void Shot(int shots);

    // Obj을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual void Enter(Col* p) override;
    virtual void Stay(Col* p) override;
    virtual void Exit(Col* p) override;
};

