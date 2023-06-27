// Dylan Yue 920058006

#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
  private:

    // numerator
    int nume;

    // denominator
    int deno;

    void set(int x, int y);

  public:
    friend istream &operator>>(istream &in, Fraction &x);
    friend ostream &operator<<(ostream &out, Fraction x);
    Fraction operator=(const Fraction& oldF);
    Fraction operator+(const Fraction& oldF);
    friend Fraction operator+(const Fraction& leftF, const Fraction& rightF);
    Fraction operator-(const Fraction& oldF);
    friend Fraction operator-(const Fraction& leftF, const Fraction& rightF);
    Fraction operator*(const Fraction& oldF);
    friend Fraction operator*(const Fraction& leftF, const Fraction& rightF);
    Fraction operator/(const Fraction& oldF);
    friend Fraction operator/(const Fraction& leftF, const Fraction& rightF);
    Fraction operator-();
    Fraction(int x, int y);
    Fraction();
    Fraction(int i);
    int getNum(void);
    int getDen(void);
    int find_gcd (int n1, int n2);
    void reduce_fraction();
};

#endif
