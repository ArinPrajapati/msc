#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int l = 0;
    int r = 0;
    int n = t.length();
    while (r < n) {
      if (t[r] == s[l]) {
        l++;
      }
      r++;
    }
    int sl = s.length();
    cout << sl << l <<endl;
    return   l == sl;
  }
};

int main() {
  Solution sn;
  cout << sn.isSubsequence("abc", "ahbgbc") << endl;

  return 0;
}
