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

vector < pair < int, string > > InviteFriends::getIdsWithName(void)
{
    vector < pair < int, string> > friendsComingToParty;

    for( int i = 0; i < jsonArray.size(); ++i )
    {
        double targetLatitude, targetLongitude;

        try
        {
            targetLatitude = stod(jsonArray[i]["latitude"].asString());

            targetLongitude = stod(jsonArray[i]["longitude"].asString());

            if ( getDistance(targetLatitude, targetLongitude) <= 100.0 )
            {
                int user_id  = jsonArray[i]["user_id"].asInt();

                string name = jsonArray[i]["name"].asString();

                friendsComingToParty.push_back( make_pair(user_id, name) );
            }
        }

        catch(const exception& e)
        {
            cout << e.what() << "\n\n";
        }
    }

    sort(friendsComingToParty.begin(), friendsComingToParty.end());

    return friendsComingToParty;
}
