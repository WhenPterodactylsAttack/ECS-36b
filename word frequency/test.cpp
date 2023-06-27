#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;

int main() {
  #include <iostream>
  #include <string>
  #include <map>
  using namespace std;

  map<string, int> word_map;
  map<string, int>::iterator it;
  string word;
  cin >> word;
  while (cin) {

      size_t found = word.find_first_not_of("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ");
      if (found == string::npos) {
          if (word_map.find(word) == word_map.end()) {
              word_map[word] = 1;
          }
          else {
              word_map[word] += 1;
          }

      }
      cout << "word_map" << " size is " << word_map.size() << endl;
      cin >> word;
  }
  for (map<string, int>::iterator i = word_map.begin(); i != word_map.end(); i++)
      cout << i->first << " " << i->second << endl;
}
