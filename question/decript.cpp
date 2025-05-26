#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
private:
  int mod(int a, int b) {
    return (a % b + b) % b;
}
public:
  vector<int> decrypt(vector<int> &code, int k) {
    vector<int> res(code.size(), 0);
    int n = code.size();

    int l = 0;
    int curr_sum = 0;
    for (int r = 0; r < n + abs(k); r++) {

      curr_sum += code[r % n];

      if (r - l + 1 > abs(k)) {
        curr_sum -= code[l % n];
        l = (l + 1) % n;
      };

      if (r - l + 1 == abs(k)) {
        if (k > 0) {
          res[mod((l - 1) , n)] = curr_sum;
        } else if (k < 0) {
          res[(r + 1) % n] = curr_sum;
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> n = {5, 7, 1, 3};
  Solution s;
  s.decrypt(n, 3);

  return 0;
}
