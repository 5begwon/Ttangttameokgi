#pragma once
#include "st.h"
class ValueManager :
    public st<ValueManager>
{
public:
    float time_scale = 1;
    int stage = 1;
    bool isWin = false;
    bool isReady = false;
    int hp = 3;
    int v_effect = 0;
    int v_back = 0;
};

#define VMGR ValueManager::G()