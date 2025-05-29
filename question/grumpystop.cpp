#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int l = 0;
    int window = 0, maxWindow = 0;
    int satisfied = 0;
    int n = customers.size();

    for (int r = 0; r < n; r++) {
      if (grumpy[r] == 1) {
        window += customers[r];
      } else {
        satisfied += customers[r];
      }

      if (r - l + 1 > minutes) {
        if (grumpy[l] == 1) {
          window -= customers[l];
        }
        l++;
      }
      maxWindow = max(maxWindow, window);
    }

    return satisfied + maxWindow;
  }
};

int main() { return 0; }
