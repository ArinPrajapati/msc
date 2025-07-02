#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class solution {
public:
  int solveLongestString(string str) {
    unordered_map<char, int> map;

    int l = 0;
    int r = 0;
    int maxlen = 0;
    int n = str.length();
    while (r < n) {
      if (map[str[r]]) {
        l++;
        map.erase(str[l - 1]);
      } else {
        maxlen = max(maxlen, r - l + 1);
        map[str[r]] = 1;
        r++;
      }
    }
    return maxlen;
  };
};

int main() {
  solution sol;
  string str = "abcabcbb";
  int result = sol.solveLongestString(str);
  cout
      << "The length of the longest substring without repeating characters is: "
      << result << endl;
  return 0;
}
