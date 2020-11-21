// Antoni Koszowski (418333) &
//    Grzegorz Zaleski (418494)

#include <iostream>
#include <string>
#include "geometry.h"
using namespace std;

Geoobject::Geoobject(bint x, bint y) : px(x), py(y) {};

bint Geoobject::x() const
{
    return px;
}

bint Geoobject::y() const
{
    return py;
}

Geoobject Geoobject::reflection() const
{
    return Geoobject(-px, py);
}

bool Geoobject::operator ==(const Geoobject &gobj) const
{
    return px == gobj.px && py == gobj.py;
}

Position::Position(bint x, bint y) : Geoobject(x, y) {};

const Position &Position::origin()
{
    static Position origin = Position(0, 0);
    return origin;
}

const Position operator +(const Position &pos, const Vector &vec)
{
    Position result = pos;
    result.px += vec.x();
    result.py += vec.y();
    return result;
}

const Position operator +(const Vector &vec, const Position &pos)
{
    Position result = pos;
    result.px += vec.x();
    result.py += vec.y();
    return result;
}

Vector::Vector(bint x, bint y) : Geoobject(x, y) {};

const Vector operator +(const Vector &vec1, const Vector &vec2)
{
    Vector result = vec1;
    result.px += vec2.px;
    result.py += vec2.py;
    return result;
}


int main ()
{
    Position a(5, 12);
    Vector b(40, 20);
    Position c(5, 11);
}