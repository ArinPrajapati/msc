#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack; 
            int n = tokens.size();

        for(int i = 0;i < n;i++){
            string token = tokens[i];
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = stack.back(); stack.pop_back();
                int a = stack.back(); stack.pop_back();
                int result;
                if(token == "+") result = a + b;
                else if(token == "-") result = a - b;
                else if(token == "*") result = a * b;
                else if(token == "/") result = a / b;
                stack.push_back(result);
            } else {
                stack.push_back(stoi(token));
            }

        }
        return stack.back();
    }
};
