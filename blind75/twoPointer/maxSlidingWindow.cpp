#include <iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if (nums.empty() || k <= 0) return result;
    int n = nums.size();
    priority_queue<vector<int>> pq;
    for (int i = 0; i < n; ++i) {
    pq.push({nums[i],i});

      if(i >= k-1){
        int windowStart = i - k + 1;
        int windowEnd = i;
        bool run = true;
        vector<int> currentMax = pq.top();

        while(run){
                if(currentMax[1] >= windowStart && currentMax[1] <= windowEnd){
                    run = false;
                }else{
                    pq.pop();
                    currentMax = pq.top();
                }
            }
        result.push_back(currentMax[0]);

        }
    }
    return result;
    }
};
