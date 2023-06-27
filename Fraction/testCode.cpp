#include <iostream>
#include<stdexcept>
using namespace std;

class Fraction {
  private:
    int nume;
    int deno;
    void set(int x, int y) {
      nume = x;
      deno = y;
      reduce_fraction();
    }
  public:

    Fraction(int x, int y) {
      set(x, y);
    }

    Fraction() {
      nume = 0;
      deno = 1;
    }

    Fraction(int i) {
      nume = i;
      deno = 1;
    }

    int getNum(void) {
      return nume;
    }

    int getDen(void) {
      return deno;
    }

    int find_gcd (int n1, int n2) {
      int gcd, remainder;

      /* Euclid's algorithm */
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

    void reduce_fraction() {
      int gcd;
      gcd = find_gcd(nume, deno);
      nume = nume / gcd;
      deno = deno / gcd;

      if(deno < 0) {
        nume = -nume;
        deno = -deno;
      }
     }


    // oldF represents the second fraction being operated on. newF is the result.
    Fraction operator+(const Fraction& oldF) {
      Fraction newF;
      newF.nume = nume * oldF.deno + oldF.nume * deno;
      newF.deno = deno * oldF.deno;
      newF.reduce_fraction();
      return newF;
    }

    // accounts for ints
    friend Fraction operator+(const Fraction& leftF, const Fraction& rightF) {
      Fraction newF;
      newF.nume = leftF.nume * rightF.deno + rightF.nume * leftF.deno;
      newF.deno = leftF.deno * rightF.deno;
      newF.reduce_fraction();
      return newF;
    }

    Fraction operator-(const Fraction& oldF) {
      Fraction newF;
      newF.nume = nume * oldF.deno - deno * oldF.nume;
      newF.deno = deno * oldF.deno;
      newF.reduce_fraction();
      return newF;
    }

    // accounts for ints
    friend Fraction operator-(const Fraction& leftF, const Fraction& rightF) {
      Fraction newF;
      newF.nume = leftF.nume * rightF.deno - rightF.nume * leftF.deno;
      newF.deno = leftF.deno * rightF.deno;
      newF.reduce_fraction();
      return newF;
    }

    Fraction operator*(const Fraction& oldF) {
      Fraction newF;
      newF.nume = nume * oldF.nume;
      newF.deno = deno * oldF.deno;
      newF.reduce_fraction();
      return newF;
    }

    friend Fraction operator*(const Fraction& leftF, const Fraction& rightF) {
      Fraction newF;
      newF.nume = rightF.nume * leftF.nume;
      newF.deno = rightF.deno * leftF.deno;
      newF.reduce_fraction();
      return newF;
    }


    Fraction operator/(const Fraction& oldF) {
      if(oldF.nume == 0) {
        throw invalid_argument("zero denominator");
      }
      Fraction newF;
      newF.nume = nume * oldF.deno;
      newF.deno = deno * oldF.nume;
      newF.reduce_fraction();

      return newF;
    }

    friend Fraction operator/(const Fraction& leftF, const Fraction& rightF) {
      if(rightF.nume == 0) {
        throw invalid_argument("zero denominator");
      }
      Fraction newF;
      newF.nume = leftF.nume * rightF.deno;
      newF.deno = leftF.deno * rightF.nume;
      newF.reduce_fraction();
      return newF;
    }

    Fraction operator-() {
      Fraction newF;
      newF.nume = -nume;
      newF.deno = deno;
      return newF;
    }

    Fraction operator=(const Fraction& oldF) {
      this->nume = oldF.nume;
      this->deno = oldF.deno;
      return *this;
    }

    friend istream &operator>>(istream &in, Fraction &x) {
      in >> x.nume >> x.deno;
      return in;
    }

    friend ostream &operator<<(ostream &out, Fraction x) {
     if(x.deno == 1) {
       out << x.nume;
     } else {
       out << x.nume << '/' << x.deno;
     }
     return out;
    }
};

void print_fraction(Fraction& f)
{
  cout << " print_fraction: " << f << endl;
}


// EXECUTES CODE
int main() {
  Fraction w;
  Fraction a;
  w = 4;
  Fraction x(4,6);
  Fraction y(5,6);
  Fraction z(0);
  cout << " w = " << w << endl;
  cout << " x = " << x << endl;
  cout << " y = " << y << endl;
  cout << " z = " << z << endl;

  cout << " x+y = " << x + y << endl;
  cout << " x-y = " << x - y << endl;
  cout << " x*y = " << x * y << endl;
  cout << " x/y = " << x / y << endl;

  cout << " -x = " << -x << endl;
  cout << " x+2 = " << x + 2 << endl;
  cout << " 2+x = " << 2 + x << endl;
  cout << " x-2 = " << x - 2 << endl;
  cout << " 2-x = " << 2 - x << endl;
  cout << " 2*x = " << 2 * x << endl;
  cout << " x*2 = " << x * 2 << endl;
  cout << " x/2 = " << x / 2 << endl;
  cout << " 2/x = " << 2 / x << endl;

  cout << " w+x+y = " << w + x + y << endl;

  print_fraction(y);

  try
  {
    cout << " x / z = " << x / z << endl;
  }
  catch ( invalid_argument& e )
  {
    cout << "Exception: " << e.what() << endl;
  }

  cout << " 2 * ( x + y ) = " << 2 * ( x + y ) << endl;
  Fraction u(12,18);
  print_fraction(u);

  cin >> a;
  cout << a << endl;
}
