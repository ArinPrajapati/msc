#include<bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> charMap;

        charMap['a'] = 1; 
        charMap['e'] = 1; 
        charMap['i'] = 1;
        charMap['o'] = 1; 
        charMap['u'] = 1;
        charMap['A'] = 1; 
        charMap['E'] = 1; 
        charMap['I'] = 1;
        charMap['O'] = 1; 
        charMap['U'] = 1;



        int l = 0;
        int r = s.length() - 1;
        while (l <= r) {
            if(charMap[s[l]] && charMap[s[r]]){
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l++;
                r--;
                continue;
            }else if(!charMap[s[l]]){
               l++;
            }else if(!charMap[s[r]]){
                r--;
            }
        }
        return s;
    }
};
