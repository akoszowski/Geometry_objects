
#ifndef ZAMLICZENIOWY_GEOMETRY_H
#define ZAMLICZENIOWY_GEOMETRY_H

#include <cstdlib>
#include <vector>
#include <initializer_list>

using bint = int32_t;
using std::vector;
using std::initializer_list;

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

    bool operator ==(const Geoobject &gobj) const;

    Geoobject operator+=(const Vector &vec);
};

class Position;

class Vector: public Geoobject
{
public:
    Vector(bint x, bint y);

    explicit Vector(const Position &pos);

    Vector reflection() const;

    friend const Vector operator +(const Vector &vec1, const Vector &vec2);
};

class Position: public Geoobject
{
public:
    Position(bint x, bint y);

    explicit Position(const Vector &vec);

    Position reflection() const;

    static const Position &origin();

    friend const Position operator +(const Position &pos, const Vector &vec);

    friend const Position operator +(const Vector &vec, const Position &pos);
};

class Rectangle
{
    bint rwidth, rheight;
    Position rpos;

public:
    Rectangle(bint width, bint height, Position pos);

    Rectangle(bint width, bint height);

    bint width() const;

    bint height() const;

    bint area() const;

    Position pos() const;

    Rectangle reflection() const;

    bool operator==(const Rectangle &rec) const;

    Rectangle operator+=(const Vector &vec);

    friend const Rectangle operator +(const Rectangle &rec, const Vector &vec);

    friend const Rectangle operator +(const Vector &vec, const Rectangle &rec);
};

class Rectangles
{
    vector<Rectangle> tab;

public:
    Rectangles();

    Rectangles(initializer_list<Rectangle> rects);

    // TODO Copy/ move constructor/assignment

    bint size() const;

    Rectangle& operator[](bint id);

    const Rectangle& operator[](bint id) const;

    bool operator==(const Rectangles &recs) const;

    Rectangles operator+=(const Vector &vec);

    friend const Rectangles operator+(const Rectangles &recs, const Vector &vec);

    friend const Rectangles operator+(const Vector &vec, const Rectangles &recs);

    friend const Rectangles operator+(Rectangles &&recs, const Vector &vec);

    friend const Rectangles operator+(const Vector &vec, Rectangles &&recs);

};

Rectangle merge_horizontally(const Rectangle &rec1, const Rectangle &rec2)

Rectangle merge_vertically(const Rectangle &rec1, const Rectangle &rec2)

Rectangle merge_all(const Rectangles &recs);

#endif //ZAMLICZENIOWY_GEOMETRY_H
