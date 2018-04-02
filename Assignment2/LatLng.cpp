#include "LatLng.h"

double LatLng::getDistance()
{
    const double sourceLatitude  = degreesToRadians(12.9611159),sourceLongitude = degreesToRadians(77.6362214);
    const double targetLatitude = degreesToRadians(latitude), targetLongitude = degreesToRadians(longitude);

    const double firstTerm  = sin(sourceLatitude) * sin(targetLatitude);
    const double secondTerm = cos(sourceLatitude) * cos(targetLatitude) * cos(abs(sourceLongitude-targetLongitude));

    double distance = EARTH_RADIUS * acos(firstTerm + secondTerm);

    return distance;
}