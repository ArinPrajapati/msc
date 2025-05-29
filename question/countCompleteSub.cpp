#include <bits/stdc++.h>
#include <ios>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int countCompleteSubarrays(vector<int> &nums) {
    unordered_map<int ,int> base;
    int n = nums.size();
    for(int i =0 ;i<n;i++){
      if(base.find(nums[i]) == base.end()){
        base[nums[i]] = 0;
      }
      base[nums[i]]++;
    }


   int l =0;
    int count = 0;
    unordered_map<int,int> inner;

    for(int r = 0;r <n;++r){
      inner[nums[r]]++;
      while(inner.size() == base.size()){
        count += nums.size() - r;
        inner[nums[l]]--;
        if(inner[nums[l]] == 0){
          inner.erase(nums[l]);
        }
        l++;
      }
    }
   return count;
  }
};

int main() { 

  Solution s;
  vector<int> d = {5,5,5,5};
  cout << s.countCompleteSubarrays(d);

  return 0; }
