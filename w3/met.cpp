#include "Met.h"
#include <cmath>

using namespace std;

Met::Met(double x, double y) : met_x(x), met_y(y) {}

double Met::getX() const
{
    return met_x;
}

double Met::getY() const
{
    return met_y;
}

double Met::getValue() const
{
    return sqrt(pow(met_x, 2) + met_y * met_y);
}

double Met::getPhi() const
{
    return atan2(met_y, met_x);
}