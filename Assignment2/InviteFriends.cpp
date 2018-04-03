#include "InviteFriends.h"

using namespace std;

double InviteFriends::getDistance(const double latitude, const double longitude)
{
    const double sourceLatitude  = degreesToRadians(12.9611159),sourceLongitude = degreesToRadians(77.6362214);
    const double targetLatitude = degreesToRadians(latitude), targetLongitude = degreesToRadians(longitude);

    const double firstTerm  = sin(sourceLatitude) * sin(targetLatitude);
    const double secondTerm = cos(sourceLatitude) * cos(targetLatitude) * cos(abs(sourceLongitude-targetLongitude));

    double distance = EARTH_RADIUS * acos(firstTerm + secondTerm);

    return distance;
}

bool InviteFriends::readFile(const string& fileName)
{
    ifstream jsonData(fileName);

    Json::Reader jsonReader;

    // return false if unbale to read the file
    if ( !jsonReader.parse(jsonData, jsonArray) )
    {
        return false;
    }

    // return true on success
    return true;
}

vector < friendInfo > InviteFriends::getFriendInfo(void)
{
    vector < friendInfo > friendsComingToParty;

    for( int i = 0; i < jsonArray.size(); ++i )
    {
        double targetLatitude, targetLongitude;

        try
        {
            targetLatitude = stod(jsonArray[i]["latitude"].asString());

            targetLongitude = stod(jsonArray[i]["longitude"].asString());

            double distance = getDistance(targetLatitude, targetLongitude);

            if (  distance <= 100.0 )
            {
                int user_id  = jsonArray[i]["user_id"].asInt();

                string name = jsonArray[i]["name"].asString();

                friendInfo tmp = { .user_id = user_id, .name = name, .distance = distance };

                friendsComingToParty.push_back( tmp );
            }
        }

        catch(const exception& e)
        {
            cout << e.what() << "\n\n";
        }
    }

    sort(friendsComingToParty.begin(), friendsComingToParty.end(), [](friendInfo& a, friendInfo& b){

        return a.user_id < b.user_id;

    });

    return friendsComingToParty;
}
