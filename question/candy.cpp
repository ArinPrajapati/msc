#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int candyEasy(vector<int>& ratings){
             int n = ratings.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    }

    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1])
            candies[i] = max(candies[i], candies[i + 1] + 1);
    }

    return accumulate(candies.begin(), candies.end(), 0);
  };
    int candy(vector<int>& ratings) {
    int peak = 0;
    int sum = 1;
    int n = ratings.size();
    int up = 0,down = 0;
    for(int i = 1;i<n;i++){
      if(ratings[i] > ratings[i-1]){
        up++;
        peak = up;
        down = 0;
        sum += 1 + up;
      }else if(ratings[i] < ratings[i-1]){
        up = 0;
        down++;
        sum += 1 +down - (down > peak ? 1: 0);
      }else{
        up = down = peak = 0;
        sum++;
      }
    }
    return sum;
    }
};


int main(){

  return 0;
}
