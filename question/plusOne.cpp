#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    int cur = digits.size() - 1;
    while (cur >= 0) {
      digits[cur] += carry;
      carry = digits[cur] / 10;
      int dit = digits[cur] % 10;

      digits[cur] = dit;
      if (carry == 0) {
        return digits;
      }
      cur--;
    }

    if(carry > 0) {
      digits.insert(digits.begin(),carry);
    }
    return digits;
  }
};

int main() {
  vector<int> v = {9,9,9};
  Solution s ;
  vector<int> z = s.plusOne(v);

  for(size_t i = 0;i < z.size() ;i++){
    cout << z[i] << " ";
  }
}
