#include "usermodel.hpp"
#include "db.h"
using namespace std;
bool UserModel::insert(User &user)
{
    // 1.组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "insert into user(name, password, state) values('%s', '%s', '%s')", // user大小写要和库里的名字相同
            user.getName().c_str(),
            user.getPwd().c_str(),
            user.getState().c_str());
    MySQL mysql; // 定义mysql对象
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            // 获取插入成功的用户数据生成的主键id。
            user.setId(mysql_insert_id(mysql.getConnection()));
            return true;
        }
    }
    return false;
}
User UserModel::query(int id)
{
    // 组装sql语句
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id = %d", id);
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql); // 真正去数据库中查的函数。
        if (res != nullptr)
        {
            // 如果查到，则获取行
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr)
            {
                // 该行中有数据
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setPwd(row[2]);
                user.setState(row[3]);

                mysql_free_result(res); // 返回之前释放资源。
                return user;
            }
        }
    }
    return User();
}
bool UserModel::updateState(User user)
{
    char sql[1024] = {0};
    sprintf(sql, "update user set state = '%s' where id = %d", // 这里要注意，%s要加单引号。
            user.getState().c_str(), 
            user.getId());
    MySQL mysql; // 定义mysql对象
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}

void UserModel::resetState()
{
    char sql[1024] = {"update user set state = 'offline' where state = 'online'"};
    MySQL mysql; // 定义mysql对象
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}
