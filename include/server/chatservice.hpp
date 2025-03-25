#ifndef CHARSERVICE_H
#define CHARSERVICE_H
#include <muduo/net/TcpConnection.h>
#include <functional>
#include <mutex>
#include <unordered_map>
#include "json.hpp"
#include "usermodel.hpp" //用到了数据操作类的对象
#include "friendmodel.hpp"
#include "offlinemessagemodel.hpp"
#include "groupmodel.hpp"
using json = nlohmann::json;
using namespace muduo::net;
using namespace muduo;
using namespace std;
using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;
class ChatService
{
public:
    static ChatService *instance();
    //登录业务
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //注册业务 填写name passward
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //一对一聊天业务
    void oneChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    //添加好友业务
    void addFriend(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 创建群组业务
    void createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 加入群组业务
    void addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 群组聊天业务
    void groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 处理注销业务
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);
    MsgHandler getHandleter(int msgid);
    //处理客户端异常退出。 异常退出也能正确修改state状态为offline。
    void clientCloseException(const TcpConnectionPtr &conn);
    //服务器异常,重置业务，比如将所有user置为offline
    void reset();
private:
    ChatService();
    //操作枚举项->操作方法函数的映射表，只查询不修改，线程安全
    unordered_map<int, MsgHandler> _msgHandlerMap;
    //数据操作类的对象，通过它访问插入查询user表的成员方法。
    UserModel _userModel;
    //用户id->连接的映射表。 
    //不同用户的上线下线会修改表中的值，非线程安全。
    unordered_map<int,TcpConnectionPtr> _userConnMap;
    //互斥锁
    mutex _connMutex;
    //离线消息操作类的对象，通过它访问插入查询offlinemessage的成员方法。
    OfflineMsgModel _offlineMsgModel;
    FriendModel _friendModel;
    GroupModel _groupModel;
};

#endif