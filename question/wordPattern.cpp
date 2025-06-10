#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    vector<string> sub;
    stringstream ss(s);
    string token;


    while(ss >> token){
      sub.push_back(token);
    }

    if(sub.size() != pattern.size()) return false;

    unordered_map<char, string> charToWord;
    unordered_map<string,char> wordToChar;

    for(int i =0;i<pattern.size();++i){
      char c = pattern[i];
      string w = sub[i];

      if(charToWord.count(c)){
        if(charToWord[c] != w) return false;
      }else{
        charToWord[c] = w;
      }

      if(wordToChar.count(w)){
        if(wordToChar[w] != c) return false;
      }else{
        wordToChar[w] = c;
      }
    }
    return false;
  }
};

int main() { return 0; }
