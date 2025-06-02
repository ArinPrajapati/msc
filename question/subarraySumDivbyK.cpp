#include <algorithm>
#include<vector>
#include <unordered_map>


using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

     unordered_map<int,int> map;
     map[0] = 1;
    int count = 0;
    int prefixSum = 0;


    for(int num : nums){
      prefixSum += num;
      int mod = ((prefixSum % k) + k) % k ;

      count += map[mod];
      map[mod]++;

    }
    return count;
    }
};

int main(){
  return 0;
}
