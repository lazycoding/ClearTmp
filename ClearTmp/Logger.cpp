#include "stdafx.h"
#include "Logger.h"


namespace ClearTmp {

    Logger::Logger(std::basic_ostream<TCHAR>& output, std::shared_ptr<IAction>& decorated)
        :decorated_(decorated), output_(output), logger_size_(0.0)
    {
    }


    Logger::~Logger()
    {
        output_ << TEXT("Total Erase: ") << logger_size_ / 1024.0 << TEXT("KB.") << std::endl;
    }

    bool Logger::Act(const WasteFile & waste_file)
    {
        std::locale loc("");
        output_.imbue(loc);
        output_ << TEXT("prepare to action:\r\n")
            << waste_file.FullName() << TEXT(" ")
            << waste_file.Ext() << TEXT(" ")
            << waste_file.Size() << std::endl;
        bool result = false;
        try
        {
            if (decorated_)
            {
                result = decorated_->Act(waste_file);
            }

            if (result)
            {
                logger_size_ += waste_file.Size() / 1024.0;
            }
        }
        catch (const std::exception& except)
        {
            t_string log;
#ifdef _UNICODE
            std::string tmp = except.what();
            log.resize(tmp.length());
            size_t converted;
            mbstowcs_s(&converted, &log[0], log.length(), except.what(), tmp.length());
#else
            log = except.what();
#endif            
            output_ << TEXT("exception:") << log << std::endl;

            return false;
        }
       
        output_ << TEXT("action completed ") << (result ? TEXT("successfully") : TEXT("unsuccessfully")) << std::endl;

        return result;
    }

}