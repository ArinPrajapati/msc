#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string reversWords(string s) {

    int n = s.length();
    vector<string> sen(n, "");

    int j = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == ' ') {
        j++;
      } else {
        sen[j] += s[i];
      }
    }

    string final = "";

    for (int i = sen.size() - 1; i >= 0; i--) {
      if (sen[i] != "" ) {
        final += sen[i] + " ";
      }
    }
    final.pop_back();
    return final;
  }
};

int main() { 
  Solution sol;
  string s = "Hello World from C++";
  string result = sol.reversWords(s);
  cout << "Reversed words: " << result << endl;
  return 0; }
