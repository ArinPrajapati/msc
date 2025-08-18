#include<bits/stdc++.h>
#include <unordered_map>

using namespace std;
class Solution {
private:
    int finder(int m , int n , unordered_map<string, int> &memo)
    {
        if(m == 1 && n == 1) return 1;
        if(m == 0 || n == 0) return 0; 
        string key1 = to_string(m) + "," + to_string(n);
        string key2 = to_string(n) + "," + to_string(m);
        string key = min(key1, key2);
        if(memo.find(key) != memo.end()) return memo[key];
        memo[key] = finder(m - 1, n, memo) + finder(m, n - 1, memo);
        return memo[key];
    }

public:
    int uniquePaths(int m, int n) {
        unordered_map<string,int> memo = {};
        return finder(m, n, memo);
    }
};



int main() {
    Solution sol;
    cout <<  sol.uniquePaths(3, 2) << endl;
    cout <<  sol.uniquePaths(18, 50) << endl;
    return 0;
}
