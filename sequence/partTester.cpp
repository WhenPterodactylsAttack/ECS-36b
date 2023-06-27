#include <iostream>
using namespace std;

void loopSort(string sequence, int n) {

  // checks if the sequence is even able to be applied
  if(n <= sequence.length()) {

    // iterates through each combination for starting letter
    for(int i = 0; i < sequence.length(); i++) {

        // iterates for every single letter in a single line
        for(int j = n; j <= sequence.length() - i; j++) {
          if(sequence.length() - i >= n) {
             cout << sequence.substr(i, j) << " | pos: " << i << endl;
          }
        }
    }
  } else {
    cout <<"No MUM found" << endl;
  }
}

void stringCompare(string s1, string s2) {
  if(s1 == s2) {
    cout << "these are the same" << endl;
  } else {
    cout << "these are different" << endl;
  }
}


// n is the smallest possible combination
void substringCompare(string s1, string s2, int n) {
  int string_max = 0;
  int pos1;
  int pos2;

  // checks if the sequence is even able to be applied
  if(n <= s1.length()) {

    // iterates through each combination for the starting letter at i
    for(int i = 0; i < s1.length() - n; ++i) {

      // iterates for every single letter in a single line
      for(int j = n; j <= s1.length() - i; ++j) {
        if(s1.length() - i >= n) {

          //iterates through possible second sequence combinations and compares
          for(int k = 0; k < s2.length() - n; ++k) {
            for(int l = n; l <= s2.length() - k; ++l) {
              if(s1.substr(i,j) == s2.substr(k,l)) {
                if(s1.substr(i,j).length() > string_max) {
                  string_max = s1.substr(i,j).length();
                  pos1 = i;
                  pos2 = k;
                }
              }
            }
          }
        }
      }
    }
  } else {
    cout <<"No MUM found" << endl;
  }
  cout << "pos1: " << pos1 << " | pos2: " << pos2 << " | longest: " << string_max << endl;
  cout << "s1: " << s1.substr(pos1, pos1 + string_max) << endl;
  cout << "s2: " << s2.substr(pos2, pos2 + string_max) << endl;
}

void substringCompare2(string s1, string s2, int n) {
  int string_max = 0;
  int pos1;
  int pos2;

  // checks if the sequence is even able to be applied
  if(n <= s1.length()) {
    // iterates through each combination for the starting letter at i
    for(int i = 0; i < (int)s1.length() - n; ++i) {

      // iterates for every single letter in a single line
      for(int j = n; j <= (int)s1.length() - i; ++j) {
        if(s2.find(s1.substr(i, j)) >= 0 && j > string_max && (unsigned)s1.length() > s2.find(s1.substr(i, j))){
          string_max = j;
          pos1 = i;
          pos2 = s2.find(s1.substr(i, j));
        }
      }
    }
  }
  if(string_max == 0) {
    cout << "no mum found" << endl;
  } else {
    string newstr = ">MUM pos1=" + to_string(pos1) + " pos2= " + to_string(pos2) + "\n";
    // returns overlapping sequence
    cout << newstr << endl;
  }
}


int main() {
  //loopSort("whowhatwhenwhere", 5);
  //stringCompare("what", "whot");
  // ostensibly should return pos1: 11 and pos2: 7
  substringCompare2("whowhatwhenwhere", "whatwhenwherewhy", 2);


}
