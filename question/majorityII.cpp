#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    int count1 = 0, count2 = 0;
    int cdt1 = 0, cdt2 = 1;

    for (int num : nums) {
      if (num == cdt1) {
        count1++;
      } else if (num == cdt2) {
        count2++;
      } else if (count1 == 0) {
        cdt1 = num;
        count1 += 1;
      } else if (count2 == 0) {
        cdt2 = num;
        count2 += 1;
      } else {
        count1 -= 1;
        count2 -= 1;
      }
    }

    count1 = count2 = 0;
    for (int num : nums) {
      if (num == cdt1) {
        count1++;
      } else if (num == cdt2) {
        count2++;
      }
    }
    vector<int> result = {};
    if (count1 > (nums.size() / 3)) {
      result.push_back(cdt1);
    }
    if (count2 > (nums.size() / 3)) {
      result.push_back(cdt2);
    }

    return result;
  }
};
