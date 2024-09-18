#include <iostream>
#include <format>
#include <string>
#include "rational.h"

using namespace std;

int main() {
    Rational a {7};
    print("a is: {}\n", a.raw_str(), a);
    return 0;
}