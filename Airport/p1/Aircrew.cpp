#include "Aircrew.h"
#include <iostream>

// for Aircrew
Aircrew::Aircrew(std::string name_str):nm(name_str) {}

const double Aircrew::maxHours(void) const {
  return 60;
}

const std::string Aircrew::name(void) const {
  return nm;
}

void Aircrew::setFlights(int i) {
  flightsTaken = i;
}
void Aircrew::setHours(double h) {
  hoursWorked = h;
}

void Aircrew::print(void) const {
  std::cout << type() << ": " << nm << " has operated " << flightsTaken << " flights for a total of " << hoursWorked << " hours this week" << std::endl;
  std::cout << "Available flights: " << (maxFlights() - flightsTaken) << std::endl;
  std::cout << "Available hours: " << (maxHours() - hoursWorked) << std::endl;
}

void Aircrew::scheduleFlight(int f, double h) const {
  std::cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight..." << std::endl;
  if((f + flightsTaken) >= maxFlights() || (hoursWorked + h) >= maxHours()) {
    std::cout << "This crew member should be replaced" << std::endl;
  } else {
    std::cout << "This crew member can be scheduled" << std::endl;
  }
  std::cout << "Done scheduling " << nm << std::endl;
}

Aircrew* Aircrew::makeAircrew(char ch, std::string name_str) {

  if(ch == 'P') {
    return new Pilot(name_str);
  }
  else if(ch == 'A') {
    return new Attendant(name_str);
  }
  else if(ch == 'T') {
    return new TaggedAttendant(name_str);
  }
  else {
    return nullptr;
  }
}

Aircrew::~Aircrew(void) {};

// UNDER CONSTRUCTION
Pilot::Pilot(std::string name_str):Aircrew(name_str) {}

const std::string Pilot::type(void) const {
  return "Pilot";
}

const int Pilot::maxFlights(void) const {
  return 5;
}

// for Attendant
Attendant::Attendant(std::string name_str):Aircrew(name_str) {}

const std::string Attendant::type(void) const {
  return "Attendant";
}

const int Attendant::maxFlights(void) const {
  return 8;
}

// for TaggedAttendant
TaggedAttendant::TaggedAttendant(std::string name_str):Aircrew(name_str) {}

const std::string TaggedAttendant::type(void) const {
  return "TaggedAttendant";
}

const int TaggedAttendant::maxFlights(void) const {
  return 8;
}

void TaggedAttendant::scheduleFlight(int f, double h) const {
  std::cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight..." << std::endl;
  if((f + flightsTaken) >= maxFlights() || (hoursWorked + (h/2)) >= maxHours()) {
    std::cout << "This crew member should be replaced" << std::endl;
  } else {
    std::cout << "This crew member can be scheduled" << std::endl;
  }
  std::cout << "Done scheduling " << nm << std::endl;
}
