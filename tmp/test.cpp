#include <iostream>

#include "test.h"

using namespace std;

const Rational operator*(const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}

ostream& operator<<(ostream& os, const Rational& obj)
{
    os << obj.n << " -- " << obj.d << endl;
    return os;
}