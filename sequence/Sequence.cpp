#include <iostream>
#include "Sequence.h"
#include<stdexcept>


Sequence::Sequence(void) {}
Sequence::Sequence(const std::string& desc_str, const std::string& seq_str):desc(desc_str),seq(seq_str) {}

std::string Sequence::findNextMutation(const Sequence& s, const int& pos) const {
  std::string firstLetter = "";
  std::string secondLetter = "";
  int mutationPos = 0;
  for(int i = pos - 1; i < (int)s.seq.length(); i++) {
    if(s.seq[i] != seq[i]) {
      firstLetter = seq[i];
      mutationPos = i;
      secondLetter = s.seq[i];
      if(mutationPos != 0) {
        return firstLetter + std::to_string(mutationPos + 1) + secondLetter;
      } else {
        break;
      }
    }
  }
  return "no mutation found";
}

Sequence findMUM(const Sequence& s1, const Sequence& s2) {
  int string_max = 0;
  int pos1;
  int pos2;

  // checks if the sequence is even able to be applied
  if(20 <= s1.seq.length()) {
    // iterates through each combination for the starting letter at i
    for(int i = 0; i < (int)s1.seq.length() - 20; ++i) {

      // iterates for every single letter in a single line
      for(int j = 20; j <= (int)s1.seq.length() - i; ++j) {
        if(s2.seq.find(s1.seq.substr(i, j)) >= 0 && j > string_max && (unsigned)s1.seq.length() > s2.seq.find(s1.seq.substr(i, j))){
          string_max = j;
          pos1 = i;
          pos2 = s2.seq.find(s1.seq.substr(i, j));
        }
      }
    }
  }
  if(string_max == 0) {
    return Sequence(">No MUM found", "");
  } else {
    std::string newstr = ">MUM pos1=" + std::to_string(pos1 + 1) + " pos2=" + std::to_string(pos2 + 1) + "\n";
    // returns overlapping sequence
    return Sequence(newstr, s1.seq.substr(pos1, string_max));
  }
}

std::istream& operator >> ( std::istream& is, Sequence& s ) {
  getline(is, s.desc, '\n');
  s.desc = s.desc + '\n';
  std::string str;
  while(is){
    getline(is, str, '\n');
    if(str.empty()){
      break;
    }
    s.seq += str;
    s.check();
  }
  return is;
}

std::ostream& operator << ( std::ostream& os, const Sequence& s ) {
  std::cout << s.desc;
  for(int i = 0; i < (int)s.seq.length(); i++){
    if(i != 0 && i % 70 == 0){
      std::cout << std::endl << s.seq[i];
    } else {
      std::cout << s.seq[i];
    }
  }
  std::cout << "\n\n";
  return os;
}

void Sequence::check(void) const {
  for(int i = 0; i < (int)seq.length(); i++) {
    if(!isupper(seq[i])) {
      throw std::invalid_argument("invalid character in sequence");
    }
  }
}
