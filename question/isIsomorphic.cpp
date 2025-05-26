#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> cs;
    unordered_map<char, int> ct;

    int n = s.size();
    vector<int> sc(n) , tc(n);

    for(int i = 0;i < n -1 ;i++){
      if(cs.find(s[i]) == cs.end()){
        cs[s[i]] = i;
      }

      if (ct.find(t[i]) == ct.end()){
        ct[t[i]] = i;
      }

      sc[i] = cs[s[i]];
      tc[i] = ct[t[i]];

    }
    return sc == tc;
  }
};

int main() { 

  Solution s;
  s.isIsomorphic("egg", "add");
  return 0; 
}
