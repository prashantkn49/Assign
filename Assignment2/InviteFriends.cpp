#include "InviteFriends.h"
#include "LatLng.h"

using namespace std;

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

            LatLng latLng (targetLatitude, targetLongitude);

            double distance = latLng.getDistance();

            if ( distance <= 100.0 )
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
