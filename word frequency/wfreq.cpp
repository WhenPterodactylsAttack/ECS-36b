#include <iostream>
#include <string>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;


int main()
{
  map<string, int> word_map;
  map<string, int>::iterator it;
  vector<string> alpha_words;
  vector<pair<string, int>> word_freq;
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
    cin >> word;
  }

  copy(word_map.begin(), word_map.end(), back_inserter<vector<pair<string, int>>>(word_freq));
    sort(word_freq.begin(), word_freq.end(), [](const pair<string, int>& l, const pair<string, int>& r)
    {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        else {
            return l.first < r.first;
        }
    });

  for (unsigned int i = 0; i < word_freq.size(); i++) {
    cout << word_freq[i].first << " " << word_freq[i].second << endl;
  }
}
