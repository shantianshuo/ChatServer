#ifndef DB_H
#define DB_H
#include <mysql/mysql.h>
#include <string>
using namespace std;

class MySQL
{
public:
    //初始化连接
    MySQL();
    //释放连接资源
    ~MySQL();
    //连接数据库
    bool connect();
    //数据库更新操作，(参数为mysql语句) 语句正确则返回true ，否则返回false
    bool update(string sql);
    
    MYSQL_RES *query(string sql);
    //获取连接
    MYSQL* getConnection();
private:
    MYSQL *_conn;
};

#endif