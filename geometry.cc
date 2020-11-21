// Antoni Koszowski (418333) &
//    Grzegorz Zaleski (418494)

#include <iostream>
#include <string>
#include <cassert>
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

bool Geoobject::operator ==(const Geoobject &gobj) const
{
    return px == gobj.px && py == gobj.py;
}

Geoobject Geoobject::operator+=(const Vector &vec)
{
    this->px += vec.px;
    this->py += vec.py;
    return *this;
}

Position::Position(bint x, bint y) : Geoobject(x, y) {};
Position::Position(const Vector &vec) : Geoobject(vec.x(), vec.y()) {};


// TODO Do poprawy, rozrysować
Position Position::reflection() const
{
    return Position(py, px);
}

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

Vector::Vector(bint x, bint y) : Geoobject(x, y) {}
Vector::Vector(const Position &pos) : Geoobject(pos.x(), pos.y()){}

Vector Vector::reflection() const
{
    return Vector(py, px);
}

const Vector operator +(const Vector &vec1, const Vector &vec2)
{
    Vector result = vec1;
    result.px += vec2.px;
    result.py += vec2.py;
    return result;
}


// Wiadomość assert
Rectangle::Rectangle(bint width, bint height, Position pos)
          : rwidth(width), rheight(height), rpos(pos)
{
    assert(width > 0 && height > 0);
};

Rectangle::Rectangle(bint width, bint height)
          :rwidth(width), rheight(height), rpos(0, 0)
{
    assert(width > 0 && height > 0);
};

bint Rectangle::height() const
{
    return rheight;
}

bint Rectangle::width() const
{
    return rwidth;
}

bint Rectangle::area() const
{
    return rheight * rwidth;
}

Position Rectangle::pos() const
{
    return rpos;
}

// TODO czy na pewno?
Rectangle Rectangle::reflection() const
{
    return Rectangle(rwidth, rheight, Position(rpos.reflection()));
}

bool Rectangle::operator==(const Rectangle &rec) const
{
    return rpos == rec.pos() && rwidth == rec.width() && rheight == rec.height();
}

Rectangle Rectangle::operator+=(const Vector &vec)
{
    this->rpos += vec;
    return *this;
}

const Rectangle operator+(const Rectangle &rec, const Vector &vec)
{
    Rectangle result = rec;
    result += vec;
    return result;
}

const Rectangle operator+(const Vector &vec, const Rectangle &rec)
{
    Rectangle result = rec;
    result += vec;
    return result;
}

Rectangles::Rectangles() : tab() {};

Rectangles::Rectangles(initializer_list<Rectangle> rects) : tab(rects) {};

// TODO Sprawdzić explicit
int main ()
{
    Position p1(1, 2);
    Vector v1(p1);
    Vector v2(2, 3);
    Position p2(v2);
    p2 = Position(v1);
    v1 = Vector(p2);

    //p2 = v1;
    //v1 = p2;
}