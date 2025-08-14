#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map <int, int> frequencyMap;
	int n = nums.size();

	for(int i = 0;i < n;i++){
	    frequencyMap[nums[i]]++;
	}

	vector<pair<int,int>> rank;

	for(const auto& pairs:frequencyMap){
	    // sorting is easy for first element instead of second therefore reverse 
	    rank.push_back({pairs.second,pairs.first});
	}

	sort(rank.rbegin(),rank.rend());

	vector<int> res;

	for(int i = 0;i < k;i++){
	    res.push_back(rank[i].second);
	};

	return res;

    }
};
