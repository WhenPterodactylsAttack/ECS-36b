#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

class WordCount {
  public:
    void start() {
      ifstream myfile("TheOdyssey.txt");
      string str;
      myfile >> str;
      while(myfile) {
        if(validWord(str)) {
          cout << str << endl;
          //storeWord(str);

        }
        myfile >> str;
      }
      //printMap();
    }
    // checks if the word is even valid
    bool validWord(string word) {
      int i = 0;
      while(word[i]) {
        if(ispunct(word[i]) || word[i] =='’') {
          return false;
        }
        ++i;
      }
      return true;
    }
    /*
    // will store the word or place it in map
    void storeWord(string word) {
      if(isdigit(wordMap[word])) {
        cout << "this word exists already" << endl;
        wordMap[word] += 1;
      } else {
        wordMap[word] = 1;
      }
    }
    */

    /*
    // prints map values
    void printMap() {
      cout << "this is supposed to do something" << endl;
      for (map<string,int>::iterator i = wordMap.begin(); i != wordMap.end(); i++ ) {
        cout << i->first << " " << i->second << endl;
      }
    }
    */

  private:
    map<string, int> wordMap;
};


int main() {
    WordCount w;
    w.start();
}
