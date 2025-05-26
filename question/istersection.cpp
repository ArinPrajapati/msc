#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<vector<int>> &nums) {
    unordered_map<int, int> aten;

    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = 0; j < nums[i].size(); j++) {
        if (aten.find(nums[i][j]) == aten.end()) {
          aten[nums[i][j]] = 1;
        }else{
          aten[nums[i][j]]++;
        }
      };
    }
    vector<int> re;
    for(auto& pair : aten){
      if(pair.second == (nums.size())){
        re.push_back(pair.first);
      };
    }

    sort(re.begin() , re.end());

    return re;
  }
};

int main() {
  vector<vector<int>> v = {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}};
  return 0;
}
