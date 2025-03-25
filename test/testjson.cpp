#include "json.hpp"
#include<iostream>
using namespace std;
using json = nlohmann::json;
int main()
{
    json js;
    js["id"] = 1;
    js["name"] = "zhaoyuan";
    cout<<js<<endl;
    return 0;
}