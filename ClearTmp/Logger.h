#pragma once
#include "IAction.h"
#include <iosfwd>
namespace ClearTmp
{
    class Logger:public IAction
    {
    public:
        Logger(std::ostream& output, std::shared_ptr<IAction>& decorated);
        ~Logger();

        // ͨ�� IAction �̳�
        virtual bool Act(const WasteFile & waste_file) override;

    private:
        std::shared_ptr<IAction>& decorated_;
        std::ostream& output_;
    };


}