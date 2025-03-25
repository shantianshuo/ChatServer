#include "db.h"
#include <muduo/base/Logging.h> //包含了muduo库的日志
static string server = "127.0.0.1"; //数据库配置信息
static string user = "root";
static string password = "123456";
static string dbname = "chat";
MySQL::MySQL()
{
    _conn = mysql_init(nullptr);
}
MySQL::~MySQL()
{
    if (_conn != nullptr)
        mysql_close(_conn);
}
bool MySQL::connect()
{
    //参数说明：存储连接数据的内存，server的ip地址，用户名，密码，所要链接的数据库，mysql端口号。
    MYSQL *p = mysql_real_connect(_conn, server.c_str(), user.c_str(),
                                  password.c_str(), dbname.c_str(), 3306, nullptr, 0);
    if (p != nullptr)
    {
        mysql_query(_conn, "set names gbk"); //数据库上的都是ASCII码，转成中文。
        LOG_INFO <<"connect mysql success!";
    }
    else
    {
        LOG_INFO <<"connect mysql fail!";
    }
    return p;
}
bool MySQL::update(string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":"
                 << sql << "更新失败!";
        return false;
    }
    return true;
}
MYSQL_RES *MySQL::query(string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ << ":"
                 << sql << "查询失败!";
        return nullptr;
    }
    return mysql_use_result(_conn);
}
MYSQL* MySQL::getConnection()
{
    return _conn;
}
