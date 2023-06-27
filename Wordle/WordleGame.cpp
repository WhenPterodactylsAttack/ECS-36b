#include <iostream>
#include <fstream>
#include <map>
#include "WordleGame.h"
using namespace std;

WordleGame::WordleGame(const string& filename) {
    string line;
    ifstream myFile(filename);
    while (getline(myFile, line)) {
        dictionary.insert(line);
    }
    done = false;
}

string WordleGame::score(const string& input) {
    string yourScore = "";
    bool inside = dictionary.find(input) != dictionary.end();
    map<unsigned int, string> m1;
    map<unsigned int, string> m2;
    if (!inside || input.length() != 5) {
        return "not in dictionary";
    } else {

      // stores input into a map
      for(unsigned int j = 0; j < 5; j++) {
        m1[j] = input[j];
      }

      // stores key into a map
      for(unsigned int k = 0; k < 5; k++) {
        m2[k] = key[k];
      }

      // iterates through each letter and assigns a character to the player's answer
      for (unsigned int i = 0; i < 5; i++) {
        if (input[i] == key[i]) {
            m1.erase(i);
            m2.erase(i);
            yourScore += "*";
        } else {
          bool found = false;
          for(unsigned int l = 0; l < 5; l++) {
            if(m1[i] == m2[l] && m2[l] != m1[l]) {
              found = true;
              yourScore += "+";
              m1.erase(i);
              m2.erase(l);
              break;
            }
          }
          if(!found) {
            yourScore += "-";
          }
        }
      }
    }
    if (yourScore == "*****") {
        done = true;
    }
    return yourScore;
}

void WordleGame::select_key(int index) {
    int word_index = index % (dictionary.size());
    set<string>::iterator it = dictionary.begin();
    advance(it, word_index - 1);
    key = *it;
}

bool WordleGame::over(void) const {
    return done;
}
