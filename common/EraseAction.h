#pragma once
#include "IAction.h"

namespace Common {
    class EraseAction :public IAction
    {
        // ͨ�� IAction �̳�
        virtual bool Act(const Archive & waste_file) override;
    };
}