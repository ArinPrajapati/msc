#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long count = 0, result = 0;
    for(int num:nums){
      if(num == 0){
        count++;
        result += count;
      }else{
        count = 0;
      }
    }
    return result;
  }
};

int main() {
  Solution s;

  vector<int> t = {1,3,0,0,2,0,0,4};
  long long d = s.zeroFilledSubarray(t);
  cout << d << " ";  
  return 0;


}
