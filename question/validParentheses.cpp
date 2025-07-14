#include<iostream>
#include<vector>


using namespace std;
#include<iostream>
#include<vector>


using namespace std;
class Solution {
public:
    bool isValid(string s) {

        if (s.size() == 1) {
            return false;
        }

        vector<char> stack;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push_back(s[i]);
            } else {
                if (stack.empty())
                    return false;
                else if (s[i] == ')' && stack.back() == '(') {
                    stack.pop_back();
                } else if (s[i] == ']' && stack.back() == '[') {
                    stack.pop_back();
                } else if (s[i] == '}' && stack.back() == '{') {
                    stack.pop_back();
                }else{
                    return false;
                }
            }
        }
        return stack.empty();
    };
};
