#include <iostream>
#include <format>
#include <string>
#include "rational.h"

using namespace std;
using std::string;

Rational Rational::reduce() const {
  if (n == 0 || d <= 3) return *this;
  for (auto div = d- 1; div; --div) {
    if (n % div == 0 && d % div ==0) {
      return Rational(n / div, d / div);
    }
  }
  return *this;
}

string Rational::str() const {
  if (d == 0) return nanstr;
  if (d == 1 || n == 0) return std::to_string(n);

  auto abs_n = abs(n);
  if (abs_n > d) {
    auto whole = abs_n / d;
    auto remainder = abs_n % d;
    if (remainder) return std::to_string(whole) + " " + Rational(remainder, d).str();
    else return std::to_string(whole);
  } else {
    return reduce().raw_str();
  }
}

string Rational::raw_str() const {
  return std::to_string(n) + "/" + std::to_string(d);
}

Rational& Rational::operator = (const Rational& rhs) {
  if (this != &rhs) {
    n = rhs.neumerator();
    d = rhs.denominator();
  }
  return *this;
}

Rational Rational::operator + (const Rational& rhs) const {
  return Rational(n * rhs.d + rhs.n * d, d * rhs.d);
}

Rational Rational::operator - (const Rational& rhs) const {
  return Rational(n * rhs.d - rhs.n * d, d * rhs.d);
}

Rational Rational::operator * (const Rational& rhs) const {
  return Rational(n * rhs.n, d * rhs.d);
}

Rational Rational::operator / (const Rational& rhs) const {
  return Rational(n * rhs.d, d * rhs.n);
}

// Rational::~Rational() {
//   n = 0;
//   d = 1;
// }

// template<>
// struct std::formatter<Rational>: std::formatter<unsigned> {
//   template<typename FormatContext>
//   auto format(const Rational& o, FormatContext& ctx) {
//     return format_to(ctx.out(), "{}", o.str());
//   }
// };