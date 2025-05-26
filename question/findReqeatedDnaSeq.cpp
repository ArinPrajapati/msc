#include "bits/stdc++.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {

    unordered_map<string, int> count;

    int p = 0;
    int q = 9;
    int n = s.size();

    while (q < n) {
      string temp = s.substr(p,q - p + 1);
      if (count[temp]) {
        count[temp]++;
      } else {
        count[temp] = 1;
      }
      q++;
      p++;
    }
    vector<string> re;

    for (auto &pair : count) {
      if (pair.second > 1) {
        re.push_back(pair.first);
      };
    }

    return re;
  }
};

int main() {
  Solution s;
  string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> sv = s.findRepeatedDnaSequences(str);

  cout << sv.size();
  for (size_t i = 0;i < sv.size();i++) {
    cout << sv[i] << endl;
  }

  return 0;
}
