#pragma once
#include "IAction.h"

namespace ClearTmp {
    class EraseAction :public IAction
    {
        // ͨ�� IAction �̳�
        virtual bool Act(const WasteFile & waste_file) override;
    };
}