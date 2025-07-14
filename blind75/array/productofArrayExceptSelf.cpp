#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
	result.push_back(1);
	int n = nums.size();
	for(int i = 1;i < n;i++){
	    result.push_back(result[i - 1] * nums[i - 1]);
	}
	int right = 1;
	for(int i = n - 2;i >= 0;i--){
	    result[i] *= right;
	    right *= nums[i];
	}
	return result;
    }
};
