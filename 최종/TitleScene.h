#pragma once
#include "Scene.h"
class TitleScene :
    public Scene
{
public:
    TitleScene(int type);

    Texture* bg;
    Texture* select;
    Texture* white;
    Texture* logo;

    Timer* wait;

    Button* start;
    Button* howtoplay;
    Button* option;
    Button* stage1;
    Button* stage2;
    Button* stage3;

    Window* option_window;
    Window* howtoplay_window;

    float alpha;

    // 1 : Intro, 2 : Title, 3 : Stage
    int type = 1;

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};
