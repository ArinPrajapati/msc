#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int sn = s.length();

    int l = 0;
    int r = 0;
    int count = 0;

    unordered_map<char, int> map;
    int maxSum = 0;

    while (r < sn) {

      if (map.find(s[r]) == map.end() || map[s[r]] == 0) {
        map[s[r]]++;
        count++;
        r++;
      } else { 
        maxSum = max(maxSum, count);
        map[s[l]]--;
        if (map[s[l]] == 0) {
          map.erase(s[l]);
        }
        l++;
        count--;
      }
    }
    maxSum = max(maxSum, count); // Check for the last window
    return maxSum;
  }
};
int main() { 
  Solution sol;
  string s = "abcabcbb"; // Example input

  cout << sol.lengthOfLongestSubstring(s) << endl;
  return 0; }
