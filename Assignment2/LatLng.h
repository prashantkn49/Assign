#ifndef LATLNG_H
#define LATLNG_H

#include <cmath>
#include <algorithm>

const double PI = atan(1) * 4;
const double EARTH_RADIUS = 6371;

class LatLng
{
public:
    LatLng()
    {
        latitude  = 0;
        longitude = 0;
    }

    LatLng(const double latitude, const double longitude)
    {
        this -> latitude  = latitude;
        this -> longitude = longitude;
    }

    double degreesToRadians(const double degrees)
    {
        return degrees * (PI / 180);
    }

    double getDistance();

    double getDistance(const double latitude, const double longitude)
    {
        this -> latitude  = latitude;
        this -> longitude = longitude;

        return getDistance();
    }

    void setLatitude(const double latitude)
    {
        this -> latitude = latitude;
    }

    void setLongitude(const double longitude)
    {
        this -> longitude = longitude;
    }

private:

    double latitude, longitude;
};
#endif
