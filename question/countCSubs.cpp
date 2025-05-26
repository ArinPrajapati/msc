#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int n = s.length();
    int totalSub = 0;
    for (int i = 0; i < n; i++) {
      int count_1 = 0;
      int count_0 = 0;
            for (int j = i; j < n; j++) {
        if (s[j] == '1') {
          count_1++;
        } else {
          count_0++;
        }

        if (count_0 <= k || count_1 <= k) {
          totalSub++;
        }
      }
    }
    return totalSub;
  }
};

int main() { return 0; }
