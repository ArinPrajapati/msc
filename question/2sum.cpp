#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {

public:
  vector<int> towSum(vector<int>& nums ,int target){

    map<int ,int> m ;

    for(int i = 0;i < sizeof(nums);i++){
      int n = target - nums[i];
      if(m.find(n) == m.end()){
        m[nums[i]] = i;
      }else{
        return {m[n],i};
      }
    }
      return{};
    }
};


int main(){
Solution sol;
  vector<int> nums = {2,7,11,15};
  int target = 9;
  vector<int> result = sol.towSum(nums,target);

     if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

  return 0;
}
