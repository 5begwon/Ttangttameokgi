#pragma once
#include "st.h"
class ValueManager :
    public st<ValueManager>
{
public:
    float time_scale = 1;
    int stage = 1;
};

#define VMGR ValueManager::G()