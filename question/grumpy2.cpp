#include <algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
      int l=0;
    int r = 0;
    int n = customers.size();
    int window_sum = 0;
    int max_window =0;
    int sum = 0;
    int limit = minutes;

    while(r < n);
      if(grumpy[r] == 0){
      sum += customers[r];
    }else{
      if(limit <= 0){
        max_window = max(max_window,window_sum);
        l--;
        
      }else{
        limit--;
        window_sum += customers[r];
      }
    }
    }
};

int main(){

  return 0;
}
