/*************************************************************************
> File Name       : String.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月30日  10时47分35秒
************************************************************************/

#include "String.h"
std::string &String::trim_blank_left(std::string &theStr)
{
    if (theStr.empty())
        return theStr;

    theStr.erase(0, theStr.find_first_not_of(" \n\r\t"));
    return theStr;
}

std::string &String::trim_blank_right(std::string &theStr)
{
    if (theStr.empty())
        return theStr;

    theStr.erase(theStr.find_last_not_of(" \n\r\t") + 1);
    return theStr;
}

std::string &String::trim_blank(std::string &theStr)
{
    return trim_blank_left(trim_blank_right(theStr));
}

std::string &String::resverse(std::string &theStr)
{
    std::reverse(theStr.begin(), theStr.end());
    return theStr;
}

std::string &String::to_upper(std::string &theStr)
{
    std::transform(theStr.begin(), theStr.end(), theStr.begin(), ::toupper);
    return theStr;
}

std::string String::to_upper_copy(std::string &theStr)
{
    std::string ret = theStr;
    std::transform(ret.begin(), ret.end(), ret.begin(), ::toupper);
    return ret;
}

std::string &String::to_lower(std::string &theStr)
{
    std::transform(theStr.begin(), theStr.end(), theStr.begin(), ::tolower);
    return theStr;
}

std::string String::to_lower_copy(std::string &theStr)
{
    std::string ret = theStr;
    std::transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

std::string String::left_n_char(std::string &theStr, size_t n)
{
    if (theStr.size() <= 0 || n <= 0)
        return "";
    if (theStr.size() <= n)
        return theStr;
    return theStr.substr(0, n);
}

std::string String::right_n_char(std::string &theStr, size_t n)
{
    if (theStr.size() <= 0 || n <= 0)
        return "";
    if (theStr.size() <= n)
        return theStr;
    return theStr.substr(theStr.size() - n, n);
}

std::string String::mid_n_char(std::string &theStr, size_t start, size_t n)
{
    if (theStr.size() <= 0 || n <= 0 || start >= theStr.size())
        return "";
    return theStr.substr(start, n);
}

std::string String::find_substr_by_key(std::string &theStr, const std::string &left,
                                       const std::string &right, bool incStart, bool incEnd)
{
    if (theStr.size() <= 0 || left.size() <= 0 || right.size() <= 0 ||
        theStr.size() < left.size() || theStr.size() < right.size())
        return "";

    std::string ret;
    std::string::size_type posBegin = theStr.find(left);
    if (posBegin != std::string::npos)
    {
        if (!incStart)
            posBegin += left.size();

        std::string::size_type posEnd = theStr.find(right, posBegin + 1);
        if (posEnd != std::string::npos)
        {
            if (!incEnd)
            {
                ret = theStr.substr(posBegin, posEnd - posBegin);
            }
            else
            {
                posEnd += right.size();
                ret = theStr.substr(posBegin, posEnd - posBegin);
            }
        }
    }
    return ret;
}

std::string String::span_including(std::string &theStr, const std::string &strKey)
{
    if (theStr.size() <= 0 || strKey.size() <= 0)
        return theStr;

    std::string ret;
    std::size_t found = theStr.find_first_of(strKey);
    while (found != std::string::npos)
    {
        ret.push_back(theStr[found]);
        found = theStr.find_first_of(strKey, found + 1);
    }
    return ret;
}

std::string String::span_excluding(std::string &theStr, const std::string &strKey)
{
    if (theStr.size() <= 0 || strKey.size() <= 0)
        return theStr;

    std::string ret;
    std::size_t fount = theStr.find_first_not_of(strKey);
    while (fount != std::string::npos)
    {
        ret.push_back(theStr[fount]);
        fount = theStr.find_last_not_of(strKey, fount + 1);
    }
    return ret;
}

bool String::start_with(std::string &theStr, const std::string &strBegin)
{
    if (theStr.size() <= 0 || strBegin.size() <= 0)
        return false;

    bool startWith = theStr.compare(0, strBegin.size(), strBegin) == 0;
    return startWith;
}

bool String::end_with(std::string &theStr, const std::string &strEnd)
{
    if (theStr.size() <= 0 || strEnd.size() <= 0)
        return false;

    bool endWith = theStr.compare(theStr.size() - strEnd.size(), strEnd.size(), strEnd) == 0;
    return endWith;
}

bool String::contain(std::string &theStr, const std::string &subStr)
{
    if (theStr.size() <= 0 || subStr.size() <= 0 || subStr.size() > theStr.size())
        return false;

    std::string::size_type pos = theStr.find(subStr);
    if (pos == std::string::npos)
        return false;

    return true;
}

bool String::is_empty(std::string &theStr)
{
    return theStr.size() > 0 ? true : false;
}

std::string String::format(const std::string theStr, ...)
{
    std::string ret;
    int size = theStr.size() * 2 + 50;
    va_list ap;
    while (true)
    {
        ret.resize(size);
        va_start(ap, theStr);
        int n = vsnprintf((char *)ret.data(), size, theStr.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size)
        {
            ret.resize(n);
            return ret;
        }

        if (n > -1)
            size = n + 1;
        else
        {
            size *= 2;
        }
    }
    return ret;
}

std::string &String::append_format(std::string &theStr, const std::string fmt, ...)
{
    std::string ret;
    int size = fmt.size() * 2 + 50;
    va_list ap;
    while (true)
    {
        ret.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)ret.data(), size, fmt.c_str(), ap);
        va_end(ap);
        if ((n > -1 && n < size))
        {
            ret.resize(n);
            theStr += ret;
            return theStr;
        }

        if (n > -1)
            size = n + 1;
        else
            size *= 2;
    }

    theStr += ret;
    return theStr;
}

std::string &String::erase(std::string &theStr, char ch)
{
    if (theStr.size() <= 0)
        return theStr;

    theStr.erase(std::remove_if(theStr.begin(), theStr.end(),
                                std::bind2nd(std::equal_to<char>(), ch)),
                 theStr.end());
    return theStr;
}

bool String::replace(std::string &theStr, const std::string &from, const std::string &to)
{
    size_t startPos = theStr.find(from);
    if (startPos == std::string::npos)
        return false;

    theStr.replace(startPos, from.length(), to);
    return true;
}

void String::replace_all(std::string &theStr, const std::string &from, const std::string &to)
{
    if (from.empty())
        return;
    size_t startPos = 0;
    while ((startPos = theStr.find(from, startPos)) != std::string::npos)
        theStr.replace(startPos, from.length(), to);
    startPos += to.length();
}

#include <strings.h>
int String::compare(const std::string &lhs, const std::string &rhs)
{
    // 这里的原作是调用头文件<string.h>中的 _stricmp() 方法。这是MSVC中的方法
    // GUN使用的是头文件<strings.h>中的 strcasecmp()方法，两者同为一种，只是换了一层包装
    return strcasecmp(lhs.c_str(), rhs.c_str());
}

void String::split(std::string &theStr, const std::string &pattern, std::vector<std::string> &arrout)
{
    arrout.clear();
    size_t idx = 0, pos = 0;
    size_t size = theStr.size();
    for (idx = 0; idx < size; ++idx)
    {
        pos = theStr.find(pattern, idx);
        if (pos != std::string::npos)
        {
            std::string s = theStr.substr(idx, pos - idx);
            if (s.size() > 0)
                arrout.push_back(s);
            idx = pos + pattern.size() - 1;
        }
        else
        {
            if (idx < size)
            {
                std::string s = theStr.substr(idx, theStr.size() - idx);
                if (s.size() > 0)
                    arrout.push_back(s);
                break;
            }
        }
    }
}

std::string String::join(std::vector<std::string> &arr_string, std::string pattern)
{
    std::string str_ret;
    if (arr_string.size() <= 0)
        return "";
    for (size_t idx = 0; idx < arr_string.size(); ++idx)
    {
        if (str_ret.size() <= 0)
            str_ret = arr_string[idx];
        else
            str_ret += pattern + arr_string[idx];
    }

    return str_ret;
}

std::wstring String::a2w_string(std::string str_a)
{
    return gbk2unicode(str_a);
}

std::string String::w2a_string(std::wstring str_w)
{
    return unicode2gbk(str_w);
}

string_t String::to_string(std::string str_a)
{
#ifdef _UNICODE
    std::wstring str_ret = a2w_string(str_a);
#else
    std::string str_ret = str_a;
#endif
    return str_ret;
}

string_t String::to_string(std::wstring str_w)
{
#ifdef _UNICODE
    std::wstring str_ret = str_w;
#else
    std::string str_ret = w2a_string(str_w);
#endif
    return str_ret;
}

std::wstring String::to_wstring(string_t str)
{
    std::wstring str_ret;

#ifdef _UNICODE
    str_ret = str;
#else
    str_ret = a2w_string(str);
#endif
    return str_ret;
}

std::string String::to_astring(string_t str)
{
    std::string str_ret;

#ifdef _UNICODE
    str_ret = w2a_string(str);
#else
    str_ret = str;
#endif
    return str_ret;
}

#if defined(CODE_CONVERT_USE_CPP11)
std::wstring String::gbk2unicode(std::string str_gbk)
{
    if (str_gbk.size() <= 0)
        return std::wstring(L"");

#if 0
	try
	{
		wstring_convert<codecvt<wchar_t, char, mbstate_t>> gbk_cvt(new codecvt<wchar_t, char, mbstate_t>("chs"));
		return gbk_cvt.from_bytes(str_gbk);
	}
	catch (exception& e)
	{
		cout << "String::gbk2unicode:" << e.what() << endl;
	}

	return std::wstring(L"");
#endif

    std::locale sys_locale("");

    const char *data_from = str_gbk.c_str();
    const char *data_from_end = str_gbk.c_str() + str_gbk.size();
    const char *data_from_next = 0;

    wchar_t *data_to = new wchar_t[str_gbk.size() + 1];
    wchar_t *data_to_end = data_to + str_gbk.size() + 1;
    wchar_t *data_to_next = 0;

    wmemset(data_to, 0, str_gbk.size() + 1);

    mbstate_t in_state = 0;
    typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
    auto result = std::use_facet<convert_facet>(sys_locale).in(in_state, data_from, data_from_end, data_from_next, data_to, data_to_end, data_to_next);
    if (result == convert_facet::ok)
    {
        std::wstring dst = data_to;
        delete[] data_to;
        return dst;
    }
    else
    {
        std::cout << "String::gbk2unicode: convert error." << std::endl;
        delete[] data_to;
        return std::wstring(L"");
    }
}

std::string String::unicode2gbk(std::wstring str_unicode)
{
    if (str_unicode.size() <= 0)
        return std::string("");

#if 0
	try
	{
		wstring_convert<codecvt<wchar_t, char, mbstate_t>> gbk_cvt(new codecvt<wchar_t, char, mbstate_t>("chs"));
		return gbk_cvt.to_bytes(str_unicode);
	}
	catch (exception& e)
	{
		cout << "String::unicode2gbk:" << e.what() << endl;
	}

	return std::string("");
#endif

    std::locale sys_locale("");

    const wchar_t *data_from = str_unicode.c_str();
    const wchar_t *data_from_end = str_unicode.c_str() + str_unicode.size();
    const wchar_t *data_from_next = 0;

    int wchar_size = 4;
    char *data_to = new char[(str_unicode.size() + 1) * wchar_size];
    char *data_to_end = data_to + (str_unicode.size() + 1) * wchar_size;
    char *data_to_next = 0;

    memset(data_to, 0, (str_unicode.size() + 1) * wchar_size);

    typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
    mbstate_t out_state = 0;
    auto result = std::use_facet<convert_facet>(sys_locale).out(out_state, data_from, data_from_end, data_from_next, data_to, data_to_end, data_to_next);
    if (result == convert_facet::ok)
    {
        std::string dst = data_to;
        delete[] data_to;
        return dst;
    }
    else
    {
        std::cout << "String::unicode2gbk: convert error." << std::endl;
        delete[] data_to;
        return std::string("");
    }
}

std::string String::gbk2utf8(std::string str_gbk)
{
    if (str_gbk.size() <= 0)
        return std::string("");

#if 0
	try
	{
		wstring_convert<codecvt_utf8<wchar_t>> utf8_cvt; //utf8=>unicode
		wstring_convert<codecvt<wchar_t, char, mbstate_t>> gbk_cvt(new codecvt<wchar_t, char, mbstate_t>("chs")); //unicode=>gbk
		wstring t = gbk_cvt.from_bytes(str_gbk);
		return utf8_cvt.to_bytes(t);
	}
	catch (exception& e)
	{
		cout << "String::gbk2utf8:" << e.what() << endl;
	}

	return std::string("");
#endif

    std::wstring str_w = gbk2unicode(str_gbk);
    return unicode2utf8(str_w);
}

std::string String::utf82gbk(std::string str_utf8)
{
    if (str_utf8.size() <= 0)
        return std::string("");

#if 0
	try
	{
		wstring_convert<codecvt_utf8<wchar_t>> utf8_cvt; //utf8=>unicode
		wstring_convert<codecvt<wchar_t, char, mbstate_t>> gbk_cvt(new codecvt<wchar_t, char, mbstate_t>("chs")); //unicode=>gbk
		wstring t = utf8_cvt.from_bytes(str_utf8);
		return gbk_cvt.to_bytes(t);
	}
	catch (exception& e)
	{
		cout << "String::utf82gbk:" << e.what() << endl;
	}

	return std::string("");
#endif

    std::wstring str_w = utf82unicode(str_utf8);
    return unicode2gbk(str_w);
}

std::string String::unicode2utf8(std::wstring str_unicode)
{
    if (str_unicode.size() <= 0)
        return std::string("");

    try
    {
        // std::wstring_convert()方法MSVC头文件是<xlocbuf>
        // GUN的头文件是<locale>
        std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_cvt;
        return utf8_cvt.to_bytes(str_unicode);
    }
    catch (std::exception &e)
    {
        std::cout << "String::unicode2utf8:" << e.what() << std::endl;
    }

    return std::string("");
}

std::wstring String::utf82unicode(std::string str_utf8)
{
    if (str_utf8.size() <= 0)
        return std::wstring(L"");

    try
    {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> utf8_cvt;
        return utf8_cvt.from_bytes(str_utf8);
    }
    catch (std::exception &e)
    {
        std::cout << "String::utf82unicode:" << e.what() << std::endl;
    }

    return std::wstring(L"");
}

#elif defined(CODE_CONVERT_USE_WIN32)
std::string String::gbk2utf8(std::string str_gbk)
{
    if (str_gbk.size() <= 0)
        return std::string("");

    //gbk=>unicode
    int nLen = MultiByteToWideChar(CP_ACP, 0, str_gbk.c_str(), str_gbk.size(), NULL, 0);
    if (nLen <= 0)
        std::string("");

    wchar_t *lpsz_w = nullptr;
    try
    {
        lpsz_w = new wchar_t[nLen + 2];
        memset(lpsz_w, 0, (nLen + 2) * sizeof(wchar_t));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "gbk2utf8 : " << e.what() << std::endl;
        return std::string("");
    }

    int nRtn = MultiByteToWideChar(CP_ACP, 0, str_gbk.c_str(), str_gbk.size(), lpsz_w, nLen);
    if (nRtn != nLen)
    {
        delete[] lpsz_w;
        return std::string("");
    }

    //unicode=>utf8
    int utf8_len = WideCharToMultiByte(CP_UTF8, 0, lpsz_w, nLen, NULL, 0, NULL, NULL);
    if (utf8_len <= 0)
        return std::string("");

    char *lpsz_m = nullptr;
    try
    {
        lpsz_m = new char[utf8_len + 2];
        memset(lpsz_m, 0, (utf8_len + 2) * sizeof(char));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "gbk2utf8 : " << e.what() << std::endl;
        return std::string("");
    }

    nRtn = WideCharToMultiByte(CP_UTF8, 0, lpsz_w, nLen, lpsz_m, utf8_len, NULL, NULL);
    delete[] lpsz_w;

    if (nRtn != utf8_len)
    {
        delete[] lpsz_m;
        return std::string("");
    }

    std::string str_utf8;
    str_utf8 = lpsz_m;
    delete[] lpsz_m;

    return str_utf8;
}

std::string String::utf82gbk(std::string str_utf8)
{
    if (str_utf8.size() <= 0)
        return std::string("");

    //utf8=>unicode
    int nLen = MultiByteToWideChar(CP_UTF8, 0, str_utf8.c_str(), str_utf8.size(), NULL, 0);
    if (nLen <= 0)
        return std::string("");

    wchar_t *lpsz_w = nullptr;
    try
    {
        lpsz_w = new wchar_t[nLen + 2];
        memset(lpsz_w, 0, (nLen + 2) * sizeof(wchar_t));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "utf82gbk : " << e.what() << std::endl;
        return std::string("");
    }

    int nRtn = MultiByteToWideChar(CP_UTF8, 0, str_utf8.c_str(), str_utf8.size(), lpsz_w, nLen);
    if (nRtn != nLen)
    {
        delete[] lpsz_w;
        return std::string("");
    }

    //unicode=>gbk
    int gbk_len = WideCharToMultiByte(CP_ACP, 0, lpsz_w, nLen, NULL, 0, NULL, NULL);
    if (gbk_len <= 0)
        return std::string("");

    char *lpsz_m = nullptr;
    try
    {
        lpsz_m = new char[gbk_len + 2];
        memset(lpsz_m, 0, (gbk_len + 2) * sizeof(char));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "utf82gbk : " << e.what() << std::endl;
        return std::string("");
    }

    nRtn = WideCharToMultiByte(CP_ACP, 0, lpsz_w, nLen, lpsz_m, gbk_len, NULL, NULL);
    delete[] lpsz_w;

    if (nRtn != gbk_len)
    {
        delete[] lpsz_m;
        return std::string("");
    }

    std::string str_gbk;
    str_gbk = lpsz_m;
    delete[] lpsz_m;
    return str_gbk;
}

std::wstring String::gbk2unicode(std::string str_gbk)
{
    if (str_gbk.size() <= 0)
        return std::wstring(L"");

    int u_len = MultiByteToWideChar(CP_ACP, 0, str_gbk.c_str(), str_gbk.size(), NULL, 0);
    if (u_len <= 0)
        return std::wstring(L"");

    wchar_t *lpsz_w = nullptr;
    try
    {
        lpsz_w = new wchar_t[u_len + 2];
        memset(lpsz_w, 0, (u_len + 2) * sizeof(wchar_t));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "gbk2unicode : " << e.what() << std::endl;
        return std::wstring(L"");
    }

    int nRtn = MultiByteToWideChar(CP_ACP, 0, str_gbk.c_str(), str_gbk.size(), lpsz_w, u_len);
    if (nRtn != u_len)
    {
        delete[] lpsz_w;
        return std::wstring(L"");
    }

    std::wstring str_unicode;
    str_unicode = lpsz_w;
    delete[] lpsz_w;
    return str_unicode;
}

std::string String::unicode2gbk(std::wstring str_unicode)
{
    if (str_unicode.size() <= 0)
        return std::string("");
    int gbk_len = WideCharToMultiByte(CP_ACP, 0, str_unicode.c_str(), str_unicode.size(), NULL, 0, NULL, NULL);
    if (gbk_len <= 0)
        return std::string("");

    char *lpsz_m = nullptr;
    try
    {
        lpsz_m = new char[gbk_len + 2];
        memset(lpsz_m, 0, (gbk_len + 2) * sizeof(char));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "unicode2gbk : " << e.what() << std::endl;
        return std::string("");
    }

    int nRtn = WideCharToMultiByte(CP_ACP, 0, str_unicode.c_str(), str_unicode.size(), lpsz_m, gbk_len, NULL, NULL);
    if (nRtn != gbk_len)
    {
        delete[] lpsz_m;
        return std::string("");
    }

    std::string str_gbk;
    str_gbk = lpsz_m;
    delete[] lpsz_m;
    return str_gbk;
}

std::wstring String::utf82unicode(std::string str_utf8)
{
    if (str_utf8.size() <= 0)
        return std::wstring(L"");
    int u_len = MultiByteToWideChar(CP_UTF8, 0, str_utf8.c_str(), str_utf8.size(), NULL, 0);
    if (u_len <= 0)
        return std::wstring(L"");

    wchar_t *lpsz_w = nullptr;
    try
    {
        lpsz_w = new wchar_t[u_len + 2];
        memset(lpsz_w, 0, (u_len + 2) * sizeof(wchar_t));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "utf82unicode : " << e.what() << std::endl;
        return std::wstring(L"");
    }

    int nRtn = MultiByteToWideChar(CP_UTF8, 0, str_utf8.c_str(), str_utf8.size(), lpsz_w, u_len);
    if (nRtn != u_len)
    {
        delete[] lpsz_w;
        return std::wstring(L"");
    }

    std::wstring str_unicode;
    str_unicode = lpsz_w;
    delete[] lpsz_w;
    return str_unicode;
}

std::string String::unicode2utf8(std::wstring str_unicode)
{
    if (str_unicode.size() <= 0)
        return std::string("");
    int utf8_len = WideCharToMultiByte(CP_UTF8, 0, str_unicode.c_str(), str_unicode.size(), NULL, 0, NULL, NULL);
    if (utf8_len <= 0)
        return std::string("");

    char *lpsz_m = nullptr;
    try
    {
        lpsz_m = new char[utf8_len + 2];
        memset(lpsz_m, 0, (utf8_len + 2) * sizeof(char));
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "unicode2utf8 : " << e.what() << std::endl;
        return std::string("");
    }

    int nRtn = WideCharToMultiByte(CP_UTF8, 0, str_unicode.c_str(), str_unicode.size(), lpsz_m, utf8_len, NULL, NULL);
    if (nRtn != utf8_len)
    {
        delete[] lpsz_m;
        return std::string("");
    }

    std::string str_utf8;
    str_utf8 = lpsz_m;
    delete[] lpsz_m;
    return str_utf8;
}

#elif defined(CODE_CONVERT_USE_ICONV)
#include "iconv_inc.h"
std::wstring String::gbk2unicode(std::string str_gbk)
{
    int nSize = str_gbk.size() + 2;
    wchar_t *pBuf = new wchar_t[nSize];
    if (!pBuf)
        return std::wstring(L"");
    wmemset(pBuf, 0, nSize);

    int ret = code_convert("UCS-2LE//TRANSLIT//IGNORE", "GBK", str_gbk.c_str(), str_gbk.size(), (char *)pBuf, nSize * sizeof(wchar_t));
    if (ret <= 0)
    {
        delete[] pBuf;
        return std::wstring(L"");
    }

    std::wstring str_unicode;
    str_unicode = pBuf;
    delete[] pBuf;
    return str_unicode;
}

std::string String::unicode2gbk(std::wstring str_unicode)
{
    int nSize = str_unicode.size() * sizeof(wchar_t) + 2;
    char *pBuf = new char[nSize];
    if (!pBuf)
        return std::string("");
    memset(pBuf, 0, nSize);

    int ret = code_convert("GBK//TRANSLIT//IGNORE", "UCS-2LE", (char *)str_unicode.c_str(), str_unicode.size() * sizeof(wchar_t), pBuf, nSize);
    if (ret <= 0)
    {
        delete[] pBuf;
        return string("");
    }

    std::string str_gbk;
    str_gbk = pBuf;
    delete[] pBuf;
    return str_gbk;
}

std::string String::gbk2utf8(std::string str_gbk)
{
    int nSize = str_gbk.size() * 2 + 2;
    char *pBuf = new char[nSize];
    if (!pBuf)
        return std::string("");
    memset(pBuf, 0, nSize);

    int ret = code_convert("UTF-8//TRANSLIT//IGNORE", "GBK", str_gbk.c_str(), str_gbk.size(), pBuf, nSize);
    if (ret <= 0)
    {
        delete[] pBuf;
        return std::string("");
    }

    std::string str_utf8;
    str_utf8 = pBuf;
    delete[] pBuf;
    return str_utf8;
}

std::string String::utf82gbk(std::string str_utf8)
{
    int nSize = str_utf8.size() * 2 + 2;
    char *pBuf = new char[nSize];
    if (!pBuf)
        return std::string("");
    memset(pBuf, 0, nSize);

    int ret = code_convert("GBK//TRANSLIT//IGNORE", "UTF-8", str_utf8.c_str(), str_utf8.size(), pBuf, nSize);
    if (ret <= 0)
    {
        delete[] pBuf;
        return std::string("");
    }

    std::string str_gbk;
    str_gbk = pBuf;
    delete[] pBuf;
    return str_gbk;
}

std::string String::unicode2utf8(std::wstring str_unicode)
{
    int nSize = str_unicode.size() * sizeof(wchar_t) + 2;
    char *pBuf = new char[nSize];
    if (!pBuf)
        return std::string("");
    memset(pBuf, 0, nSize);

    int ret = code_convert("UTF-8//TRANSLIT//IGNORE", "UCS-2LE", (char *)str_unicode.c_str(), str_unicode.size() * sizeof(wchar_t), pBuf, nSize);
    if (ret <= 0)
    {
        delete[] pBuf;
        return std::string("");
    }

    std::string str_utf8;
    str_utf8 = pBuf;
    delete[] pBuf;
    return str_utf8;
}

std::wstring String::utf82unicode(std::string str_utf8)
{
    int nSize = str_utf8.size() + 2;
    wchar_t *pBuf = new wchar_t[nSize];
    if (!pBuf)
        return std::wstring(L"");
    wmemset(pBuf, 0, nSize);

    int ret = code_convert("UCS-2LE//TRANSLIT//IGNORE", "UTF-8", str_utf8.c_str(), str_utf8.size(), (char *)pBuf, nSize * sizeof(wchar_t));
    if (ret <= 0)
    {
        delete[] pBuf;
        return std::wstring(L"");
    }

    std::wstring str_unicode;
    str_unicode = pBuf;
    delete[] pBuf;
    return str_unicode;
}
#else
#error String required must define CODE_CONVERT_USE_CPP11 or CODE_CONVERT_USE_WIN32 or CODE_CONVERT_USE_ICONV.
#endif