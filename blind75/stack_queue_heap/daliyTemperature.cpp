#include<vector>
#include<iostream>
#include<stack>


using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> stack;
        vector<int> result(n,0);

        for(int i = n - 1;i >= 0;i--){
            while(!stack.empty() && temperatures[stack.back()] <= temperatures[i]){
                    stack.pop_back();
            }
            if(!stack.empty()){
            result[i] = stack.back() - i ;
            

            }                        }

            return result;

        }

};
