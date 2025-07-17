#include <utility>
#include<vector>
#include<iostream>
#include<algorithm>


using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> ranges;

        for(int i = 0;i < heights.size();i++){
            ranges.push_back({heights[i],i});
        }

        sort(ranges.rbegin(),ranges.rend());

        if(ranges.size() == 1){
            return ranges[0].first;
        }
        int start = min(ranges[0].second,ranges[1].second);
        int end = max(ranges[0].second,ranges[1].second);

        int areas = ranges[1].first * end - start + 1;

        return areas;
    }
};
