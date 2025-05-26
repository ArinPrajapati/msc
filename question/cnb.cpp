#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
      int n = nums.size();
    unordered_map<int,int> hash;

    for(int i = 0;i < n;i++){
      if(hash.find(nums[i]) == hash.end()){
        hash[nums[i]] = i;
      }else{
        int j = hash[nums[i]] - i;
        if(abs(j) <= k){
          return true;
        }else{
          hash[nums[i]] = i;
        }
      }
    }

    return false;
  }
};

int main() {
  vector<int> n = {1,0,1,1};
  Solution s;
  cout << s.containsNearbyDuplicate(n,1);
  return 0;
}
