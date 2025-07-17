#include<iostream>
#include<vector>


using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", n, n);
        return result;
    }
    void generate(vector<string>& result, string current, int open, int close) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        if (open > 0) {
            generate(result, current + '(', open - 1, close);
        }
        if (close > open) {
            generate(result, current + ')', open, close - 1);
        }
    }
};
