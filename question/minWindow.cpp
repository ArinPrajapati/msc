#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    if (t == "")
      return "";

    unordered_map<char, int> map;

    for (char ch : t) {
      map[ch]++;
    }

    int l = 0;
    int r = 0;
    int startIndex = -1;
    int minlen = INT_MAX;
    int count = 0;

    while (r < s.length()) {
      char i = s[r];
      if (map.find(i) != map.end()) {
        if (map[i] > 0) {
          count++;
        }
        map[i]--;
      }

      while (count == t.length()) {
        if (r - l + 1 < minlen) {
          minlen = r - l + 1;
          startIndex = l;
        }
        char leftChar = s[l];
        if (map.find(leftChar) != map.end()) {
          map[leftChar]++;
          if (map[leftChar] > 0) {
            count--;
          }
        }
        l++;
      }
      r++;
    }
    return startIndex == -1 ? "" : s.substr(startIndex, minlen);
  }
};

int main() {
  Solution sol;
  string s = "ADOBECODEBANC";
  string t = "ABC";
  string result = sol.minWindow(s, t);
  cout << "Minimum window substring: " << result << endl;
  return 0;
}
