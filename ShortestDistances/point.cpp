#include <cmath>
#include <iomanip>
#include "point.h"

/// \brief
/// Constructor that sets the x and y coordinates for
/// the Point object
Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

/// \brief
/// Destuctor
Point::~Point()
{

}

/// \brief
/// Returns the Euclidean distance between this Point
/// and the Point*parameter to the function
double Point::distanceTo(Point* other)
{
    double dx = x - other->x;
    double dy = y - other->y;
    return sqrt(dx * dx + dy * dy);
}

/// \brief
/// Produces a string representation of this Point.
ostream& operator << (ostream& out, Point& point)
{
    out << setw(3) << point.x << setw(4) << point.y << " ";
    return out;
}
