
#ifndef ZAMLICZENIOWY_GEOMETRY_H
#define ZAMLICZENIOWY_GEOMETRY_H

#include <cstdlib>
using bint = int32_t;

class Vector;

class Geoobject
{
    protected:
    bint px, py;

    // Zagwarantowanie niekonstruktowności klasy.
    Geoobject (bint x, bint y);

    public:

    bint x() const;

    bint y() const;

    Geoobject reflection() const;

    bool operator ==(const Geoobject &gobj) const;
};

class Position;

class Vector: public Geoobject
{
    public:
    Vector(bint x, bint y);

    friend const Vector operator +(const Vector &vec1, const Vector &vec2);
};

class Position: public Geoobject
{
    public:
    Position(bint x, bint y);

    static const Position &origin();

    friend const Position operator +(const Position &pos, const Vector &vec);

    friend const Position operator +(const Vector &vec, const Position &pos);
};

#endif //ZAMLICZENIOWY_GEOMETRY_H
