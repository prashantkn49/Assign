#ifndef INVITE_FRIENDS_H
#define INVITE_FRIENDS_H

#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

const double PI = atan(1) * 4;
const double EARTH_RADIUS = 6371;

class InviteFriends
{
public:
	double degreesToRadians(const double degrees)
    {
        return degrees * (PI / 180);
    }

    double getDistance(const double latitude, const double longitude);

    bool readFile(const std::string& fileName);

    std::vector < std::pair < int, std::string > > getIdsWithName();

private:
	Json::Value jsonArray;
};
#endif
