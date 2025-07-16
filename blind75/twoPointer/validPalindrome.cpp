#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
       string purifiedS = "";

        for(char c : s){
        if(isalnum(c)){
            purifiedS += c;
         } 
        }

      int l = 0;
      int r = purifiedS.size() - 1;


      while (l < r) {
            if (tolower(purifiedS[l]) != tolower(purifiedS[r])) {
                return false;
            }
            l++;
            r--;
      }

    return true;

    }
};
