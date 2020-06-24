/*************************************************************************
> File Name       : 12.14.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月21日  15时45分20秒
************************************************************************/
#include <iostream>
using std::cout, std::endl;
#include <memory>
#include <string>
using std::string;

struct connection
{
    string ip;
    int port;
    connection(string theIp, int thePort) : ip(theIp), port(thePort) {}
};

struct destination
{
    string ip;
    int port;
    destination(string theIp, int thePort) : ip(theIp), port(thePort) {}
};

connection connect(destination *ptrDest) // 打开连接
{
    std::shared_ptr<connection> ptrConnect(new connection(ptrDest->ip, ptrDest->port));
    cout << "creating connrction(" << ptrConnect.use_count() << ")" << endl;
    return *ptrConnect;
}

void disconnect(connection ptrConnect)
{
    cout << "connection close(" << ptrConnect.ip << ":" << ptrConnect.port << ")" << endl;
}

void end_connection(connection *ptrConnect)
{
    disconnect(*ptrConnect);
}

void f(destination &dest)
{
    connection c = connect(&dest);
    std::shared_ptr<connection> p(&c, end_connection);
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main(int argc, const char *argv[])
{
    destination dest("220.111.111", 10086);
    f(dest);

    system("pause");
    return 0;
}