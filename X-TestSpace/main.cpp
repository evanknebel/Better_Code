#include "mathutils.h"
#include "vec2.h"

#include <iostream>
#include <cassert>

int main()
{
    // equality and inequality
    {
        vec2 a = { 5,3 };
        vec2 b = { 4,2 };
        vec2 c = { 0,1 };
        vec2 d = { 0,1 };

        assert((a + b) == (vec2{ 9, 5 }));
        assert(c == d);
        assert(a != c);
    }


    vec2 test;
    test.x = 5;
    test.y = 20;

    vec2 testB;
    testB.x = 13;
    testB.y = 4;

    vec2 result = test + testB;

    vec2 num;
    num.x = 0;
    num.y = 0;

    num += test;

    bool eq = num == test;
    bool ieq = num == testB;

    std::cout << "ALL TESTS OK" << std::endl;
}