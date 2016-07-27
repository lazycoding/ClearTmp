// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <exception>
#include <windows.h>
#define RUN_TEST
#undef __TEXT
#undef TEXT

#ifdef _UNICODE
#define t_string std::wstring
#define __TEXT(quote) L##quote

#else
#define t_string std::string
#define __TEXT(quote) quote
#endif 

#define TEXT(quote) __TEXT(quote)

namespace ClearTmp
{
    namespace util
    {
        t_string NormallizeSearchPath(const t_string& path);
        t_string FormatErrorMessage();
    }
}