//为了剥离业务层和数据层的ORM层。
#ifndef USERMODEL_H
#define USERMODEL_H
#include "user.hpp"
// User表的数据操作类: 插入
class UserModel
{
public:
    // 参数为User定义的对象，按照这个对象的成员变量，在user表中增加新的一项。
    // 插入成功则返回ture。 插入的同时，就调用setId()设置了User对象的主键id
    bool insert(User &user);
    //参数为用户主键id，返回user对象。
    User query(int id);
    //参数为User定义的对象，该user对象只需要id和state初始化即可，id用于查找数据库。
    //因为需要操作数据库。更新成功返回true
    bool updateState(User user);
    //重置状态信息  直接把所有的online 改为 offline
    void resetState();

};
#endif