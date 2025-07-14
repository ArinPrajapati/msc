#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> hash;

       int n = strs.size();
       for(int i = 0;i < n ;i++){
	    vector<int> count(26,0);

	    for(char c:strs[i]){
		count[c - 'a']++;
	    }

	    string k;
	    for(int i : count){
		k += to_string(i) + "#";
	    }

	    hash[k].push_back(strs[i]);
	}

	vector<vector<string>> result;
	for(auto& entry:hash){
	    result.push_back(entry.second);
	}

	return result;
    }
};
