#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
  void backtrack(string s, int index, vector<vector<string>> &res,
                 vector<string> &part) {
    if (index == s.length()) {
      res.push_back(part);
      return;
    }
    for (int i = index; i < s.length(); i++) {
      if (isPalindrome(s, index, i)) {
        part.push_back(s.substr(index, i - index + 1));
        backtrack(s, i + 1, res, part);
        part.pop_back();
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> part;
    backtrack(s, 0, res, part);
    return res;
  }
};
