//
// Created by zy on 2019/8/4.
//

#ifndef CPPDEMO_TEST_H
#define CPPDEMO_TEST_H

#include <iostream>

using namespace std;

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1):d(numerator), n(denominator){}

private:
    int d, n;

    friend const Rational operator*(const Rational& lhs, const Rational& rhs);
    friend ostream& operator<<(ostream& os, const Rational& obj);
};

class Base{
public:
    virtual void func()
    {
        cout << "Base func" << endl;
    }

    void func(int i)
    {
        cout << "Base func " << i << endl;
    }
};

class Derived: public Base {
public:
    void func()
    {
        cout << "Derived func" << endl;
    }

    void func(int i)
    {
        cout << "Derived func " << i << endl;
    }
};


#endif //CPPDEMO_TEST_H
