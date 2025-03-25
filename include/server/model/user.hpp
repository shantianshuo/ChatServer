#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
// User表成员: id name password state 有get 和 set方法操作成员变量。
class User
{
public:
    User(int id = -1, string name = "", string password = "", string state = "offline")
    {
        this->id = id;
        this->name = name;
        this->password = password;
        this->state = state;
    }
    void setId(int id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setPwd(string pwd) { this->password = pwd; }
    void setState(string state) { this->state = state; }

    int getId() { return this->id; }
    string getName() { return this->name; }
    string getPwd() { return this->password; }
    string getState() { return this->state; }

private:
    int id; // 不能加下横杠，为了和库里的名字保持相同。
    string name;
    string password;
    string state;
};

#endif