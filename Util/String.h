/*************************************************************************
> File Name       : String.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月30日  09时15分49秒
************************************************************************/
#ifndef __STRING_H__
#define __STRING_H__

/*
  *基于C++STL封装的字符串工具
  *添加了一些使用功能，同时宽窄字符的转换功能
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <functional>
#include <codecvt>
#include <iostream>
#include <locale> // for std::wstring_convert()
#include <numeric>
#include <windows.h>

// 检测是否是Unicode环境（Unicode环境使用宽字符
#ifdef _UNICODE
#define string_t std::wstring
#else
#define string_t std::string
#endif

// 开发环境宏定义
#define CODE_CONVERT_USE_CPP11
//#define CODE_CONVERT_USE_WIN32
//#define CODE_CONVERT_USE_ICONV

class String
{
public:
    // 构造和析构
    String() {}
    ~String() {}

public:
    static std::string &trim_blank_left(std::string &theStr);  // 去掉字符串左侧的空白字符
    static std::string &trim_blank_right(std::string &theStr); // 去嗲字符串右侧的空白字符
    static std::string &trim_blank(std::string &theStr);       // 去掉字符串左右两侧的空白字符
    static std::string &resverse(std::string &theStr);         // 字符串首尾反转

    static std::string &to_upper(std::string &theStr);     // 字符串转换成大写
    static std::string to_upper_copy(std::string &theStr); // 生成一个当前字符串大写的拷贝

    static std::string &to_lower(std::string &theStr);     // 将字符串转换成小写
    static std::string to_lower_copy(std::string &theStr); // 生成一个当前字符串小写的拷贝

    static std::string left_n_char(std::string &theStr, size_t n);              //返回当前字符串左侧的n个字符
    static std::string right_n_char(std::string &theStr, size_t n);             // 返回当前字符串右侧的n个字符
    static std::string mid_n_char(std::string &theStr, size_t start, size_t n); // 返回当前字符串中间的n个字符
    static std::string find_substr_by_key(std::string &theStr, const std::string &left,
                                          const std::string &right, bool incStart = false, bool incEnd = false); // 以首尾关键字查找字符串
    static std::string span_including(std::string &theStr, const std::string &strKey);                           // 返回theStr中包含strKey中任意字符的字串
    static std::string span_excluding(std::string &theStr, const std::string &strKey);                           // 返回theStr中不包含strKey中任意字符的字串

    static bool start_with(std::string &theStr, const std::string &strBegin);                             // theStr字符串是否以strBegin字符串开头
    static bool end_with(std::string &theStr, const std::string &strEnd);                                 // theStr字符串是否以strEnd字符串结尾
    static bool contain(std::string &theStr, const std::string &subStr);                                  // theStr字符串是否包含subStr子串
    static bool is_empty(std::string &theStr);                                                            // theStr是否尾空串
    static std::string format(const std::string theStr, ...);                                             // 格式化字符串
    static std::string &append_format(std::string &theStr, const std::string fmt, ...);                   // 格式化字符串并添加到theStr结尾
    static std::string &erase(std::string &theStr, char ch);                                              // 删除theStr字符串中的所有ch字符
    static bool replace(std::string &theStr, const std::string &from, const std::string &to);             // 替换theStr字符串中的第一处from字符串为to字符串
    static void replace_all(std::string &theStr, const std::string &from, const std::string &to);         // 替换theStr字符串所有from字符串为to字符串
    static int compare(const std::string &lhs, const std::string &rhs);                                   // 不区分大小写比较字符串
    static void split(std::string &theStr, const std::string &pattern, std::vector<std::string> &arrout); // 将theStr字符串以pattern分隔符进行分割，结果存放到arrout数组中
    static std::string join(std::vector<std::string> &arrStr, const std::string pattern = "");            //将arrStr数组中的多个字符串以pattern分隔符进行连接

    static std::wstring a2w_string(std::string aStr); // 将窄字节字符串转换成宽字节Unicode字符串
    static std::string w2a_string(std::wstring wStr); // 将宽字节Unicode字符串转换成窄字节字符串

    static string_t to_string(std::string aStr);  // 将窄字节字符串转换成通用的字符串类型string_t
    static string_t to_string(std::wstring wStr); // 将宽字节Unicode字符串转换成窄字节字符串

    static std::wstring to_wstring(string_t theStr); // 将通用的字符串string_t转换成宽字节Unicode字符串
    static std::string to_astring(string_t theStr);  // 将通用的字符串类型string_t转换成窄字节字符串

public:
    static std::wstring gbk2unicode(std::string gbkStr);     // 窄字节转换成Unicode宽字节
    static std::string unicode2gbk(std::wstring unicodeStr); // Unicode宽字节转换成窄字节

    static std::string gbk2utf8(std::string gbkStr);  // 窄字节转换成utf8编码的字符串
    static std::string utf82gbk(std::string utf8Str); // utf8编码的字符串转换成窄字节

    static std::string unicode2utf8(std::wstring unicodeStr); // Unicode宽字节字符串转换成utf8编码的字符串
    static std::wstring utf82unicode(std::string utf8Str);    // utf8编码的字符串转换成Unicode宽字节字符串
};

#endif // __STRING_H__