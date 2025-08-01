#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int,int> hash;
	
	for(int i = 0;i < nums.size();i++){
	  if(hash.find(target - nums[i]) != hash.end()){	    return {i,hash[target-nums[i]]};
	   }else{
	    hash[nums[i]] = i;
	}
	}
	return {-1,-1};
    }
};
