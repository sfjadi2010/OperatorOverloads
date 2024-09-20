#include <iostream>
#include <format>
#include <string>
#include "rational.h"

using namespace std;

int main() {
    Rational a {7};
    print("a is: {}\n", a.raw_str(), a);

    Rational b(25, 27);
    print("b is: {} = {}\n", b.raw_str(), b);

    auto c = b;
    print("c is: {} = {}\n", c.raw_str(), c);

    Rational d;
    print("d is: {} = {}\n", d.raw_str(), d);

    d = c;
    print("d is: {} = {}\n", d.raw_str(), d);

    auto& e = d;
    d = e;
    return 0;
}