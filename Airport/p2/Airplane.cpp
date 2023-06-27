#include "Airplane.h"
#include <iostream>

Airplane::Airplane(int n): maxContainers(n) {
  numContainers = 0;
}

int Airplane::maxLoad(void) const {
  return maxContainers;
}

int Airplane::currentLoad(void) const {
  return numContainers;
}

bool Airplane::addContainers(int n) {
  if(n <= (maxContainers - numContainers)) {
    numContainers += n;
    return true;
  } else {
    return false;
  }
}
