#pragma once
#include "IAction.h"

namespace ClearTmp {
    class EraseAction :public IAction
    {
        // ͨ�� IAction �̳�
        virtual bool Act(const Archive & waste_file) override;
    };
}