//Dylan Yue 920058006
#include <iostream>
#include<stdexcept>
#include "Fraction.h"
using namespace std;

void Fraction::set(int x, int y) {
  nume = x;
  deno = y;
  reduce_fraction();
}

Fraction::Fraction(int x, int y) {
  set(x, y);
}

Fraction::Fraction(void) {
  nume = 0;
  deno = 1;
}

Fraction::Fraction(int i) {
  nume = i;
  deno = 1;
}

int Fraction::getNum(void) {
  return nume;
}

int Fraction::getDen(void) {
  return deno;
}

int Fraction::find_gcd (int n1, int n2) {
  int gcd, remainder;

  remainder = n1 % n2;
  while ( remainder != 0 )
  {
    n1 = n2;
    n2 = remainder;
    remainder = n1 % n2;
  }
  gcd = n2;

  return (gcd);
}

void Fraction::reduce_fraction() {
  int gcd;
  gcd = find_gcd(nume, deno);
  nume = nume / gcd;
  deno = deno / gcd;

  if(deno < 0) {
    nume = -nume;
    deno = -deno;
  }
}

friend istream Fraction::operator>>(istream &in, Fraction &x) {
  in >> x.nume >> x.deno;
  return in;
}

friend ostream Fraction::operator<<(ostream &out, Fraction x) {
 if(x.deno == 1) {
   out << x.nume;
 } else {
   out << x.nume << '/' << x.deno;
 }
 return out;
}

// oldF represents the second fraction being operated on. newF is the result.
Fraction Fraction::operator+(const Fraction& oldF) {
  Fraction newF;
  newF.nume = nume * oldF.deno + oldF.nume * deno;
  newF.deno = deno * oldF.deno;
  newF.reduce_fraction();
  return newF;
}

// accounts for ints
friend Fraction Fraction::operator+(const Fraction& leftF, const Fraction& rightF) {
  Fraction newF;
  newF.nume = leftF.nume * rightF.deno + rightF.nume * leftF.deno;
  newF.deno = leftF.deno * rightF.deno;
  newF.reduce_fraction();
  return newF;
}

Fraction Fraction::operator-(const Fraction& oldF) {
  Fraction newF;
  newF.nume = nume * oldF.deno - deno * oldF.nume;
  newF.deno = deno * oldF.deno;
  newF.reduce_fraction();
  return newF;
}

// accounts for ints
friend Fraction Fraction::operator-(const Fraction& leftF, const Fraction& rightF) {
  Fraction newF;
  newF.nume = leftF.nume * rightF.deno - rightF.nume * leftF.deno;
  newF.deno = leftF.deno * rightF.deno;
  newF.reduce_fraction();
  return newF;
}

Fraction Fraction::operator*(const Fraction& oldF) {
  Fraction newF;
  newF.nume = nume * oldF.nume;
  newF.deno = deno * oldF.deno;
  newF.reduce_fraction();
  return newF;
}

friend Fraction Fraction::operator*(const Fraction& leftF, const Fraction& rightF) {
  Fraction newF;
  newF.nume = rightF.nume * leftF.nume;
  newF.deno = rightF.deno * leftF.deno;
  newF.reduce_fraction();
  return newF;
}


Fraction Fraction::operator/(const Fraction& oldF) {
  if(oldF.nume == 0) {
    throw invalid_argument("zero denominator");
  }
  Fraction newF;
  newF.nume = nume * oldF.deno;
  newF.deno = deno * oldF.nume;
  newF.reduce_fraction();

  return newF;
}

friend Fraction Fraction::operator/(const Fraction& leftF, const Fraction& rightF) {
  if(rightF.nume == 0) {
    throw invalid_argument("zero denominator");
  }
  Fraction newF;
  newF.nume = leftF.nume * rightF.deno;
  newF.deno = leftF.deno * rightF.nume;
  newF.reduce_fraction();
  return newF;
}

Fraction Fraction::operator-() {
  Fraction newF;
  newF.nume = -nume;
  newF.deno = deno;
  return newF;
}

Fraction Fraction::operator=(const Fraction& oldF) {
  this->nume = oldF.nume;
  this->deno = oldF.deno;
  return *this;
}
