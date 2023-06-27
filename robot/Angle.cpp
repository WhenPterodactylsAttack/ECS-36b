// Dylan Yue 920058006
#include <iostream>
#include "Angle.h"
using namespace std;

void Angle::set(int t) {
  theta = t;
}
    Angle::Angle(void) {
      set(30);
    }

    int Angle::get(void) {
      return theta;
    }

    void Angle::change(int dt) {
      if((theta + dt) > 60) {
        theta = 60;
      } else if((theta + dt) < -120) {
        theta = -120;
      } else {
        theta += dt;
      }
    }

    void Angle::print(void) {
      cout << "angle: " << theta << endl;
    }
