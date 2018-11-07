#include <iostream>

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

using namespace std;

/// \brief
/// This class encapsulates the x and y co-ordinates of
/// a point in a Cartesian plane and has functionality to
/// determine the distance between two instances of Point objects.
class Point
{

public:

    /// \brief
    /// Constructor that sets the x and y coordinates for
    /// the Point object
    Point(double, double);

    /// \brief
    /// Destuctor
    ~Point();

    /// \brief
    /// Returns the Euclidean distance between this Point
    /// and the Point*parameter to the function
    double distanceTo(Point*);

    /// \brief
    /// Produces a string representation of this Point.
    friend ostream& operator << (ostream&, Point&);

private:

    double x;

    double y;
};

#endif // POINT_H_INCLUDED
