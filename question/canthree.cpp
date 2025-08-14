#include<vector>

using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int count = 0;

        for(int i = 0; i < arr.size();i++){
            count += arr[i];
        }
         if(count % 3 != 0){
            return false;
        }

        count = count/3;
               
        int sum = 0;
        

        for(int i = 0;i < arr.size();i++){
            sum += arr[i];
            if(sum == count){
             count--;
             sum = 0;
            }
        }

      if(count == 0){
          return true;
      } else {
          return false;
      }
    }
};
