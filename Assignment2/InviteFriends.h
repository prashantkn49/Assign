#ifndef INVITE_FRIENDS_H
#define INVITE_FRIENDS_H

#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

typedef struct
{
    int user_id;
    std::string name;
    double distance;

} friendInfo;

class InviteFriends
{
public:

    bool readFile(const std::string& fileName);

    std::vector < friendInfo > getFriendInfo();

private:

    Json::Value jsonArray;
};
#endif
