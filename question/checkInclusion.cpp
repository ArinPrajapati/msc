#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();

    if (len1 > len2)
      return false;

    vector<int> map1(26, 0), map2(26, 0);

    for (int i = 0; i < len1; ++i) {
      cout << i << " ";
      cout << i << endl;
      map1[s1[i] - 'a']++;
      map2[s2[i] - 'a']++;
    }

    if (map1 == map2)
      return true;

    for (int i = len1; i < len2; ++i) {
      map2[s2[i] - 'a']++;
      map2[s2[i - len1] - 'a']--;

      if (map1 == map2)
        return true;
    }
    return false;
  }
};

int main() {
  Solution sol;
  string s1 = "ab";
  string s2 = "eidbaooo";

  bool result = sol.checkInclusion(s1, s2);
  cout << (result ? "true" : "false") << endl;

  s1 = "ab";
  s2 = "eidboaoo";

  result = sol.checkInclusion(s1, s2);
  cout << (result ? "true" : "false") << endl;
  return 0;
}
