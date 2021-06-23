#pragma once
class HotKey :
    public st<HotKey>
{
public:
    HotKey();
    ~HotKey() { ; };

    void Reset() { player = OBJ->Find("player"); };

    void Update();

    void F1();
    void F2();
    void F3();
    void F4();
    void F5();
    void F6();
    void F7();

    Obj* player;
};

#define HOT HotKey::G()