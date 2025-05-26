#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  int divideAFind(const string &s, int start, int end, int k) {
    if (end - start < k)
      return 0;

    int freq[26] = {0};

    for (int i = start; i < end; ++i) {
      freq[s[i] - 'a']++;
    }

    for (int i = start; i < end; ++i) {
      if (freq[s[i] - 'a'] < k) {
        int next = i + 1;
        while (next < end && freq[s[next] - 'a'] < k) {
          next++;
        }
        int left = divideAFind(s, start,i,k);
        int right = divideAFind(s, next,end,k);
        return max(left,right);
      }
    }

    return end - start;
  }

public:
  int longestSubstring(string s, int k) {
    return divideAFind(s, 0, s.size(), k);
  }
};

int main() {
  string s = "ababbc";
  Solution st;

  cout << st.longestSubstring(s, 2);

  return 0;
}
