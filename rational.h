#include <iostream>
#include <format>
#include <string>

using namespace std;
using std::string;

constexpr void print(const string_view str_fmt, auto&&... args) {
    fputs(vformat(str_fmt, make_format_args(args...)).c_str(), stdout);
}

const string nanstr {"NaN"};

class Rational {
  int n {0};
  int d {1};
public:
  Rational(int numerator = 0, int denominator = 1) : n(numerator), d(denominator) {}
  Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) {}
  ~Rational() {}
  int neumerator() const { return n; }
  int denominator() const { return d; }
  Rational reduce() const;
  string str() const;
  string raw_str() const;
  Rational& operator = (const Rational&);
  Rational& operator + (const Rational&) const;
  Rational& operator - (const Rational&) const;
  Rational& operator * (const Rational&) const;
  Rational& operator / (const Rational&) const;
};