#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> count;

    for (int i = 0; i < magazine.length(); i++) {
      count[magazine[i]]++;
    }

    for(int i =0;i < ransomNote.length();i++){
      if(count.find(ransomNote[i]) == count.end()){
        return false;
      }else if(count[ransomNote[i]] == 0){
        return false;
      }else{
        count[ransomNote[i]]--;
      }
    }
    return true;
  }
};

int main() { 
  Solution sol;
  cout << sol.canConstruct("aa","b");
  return 0;
}
