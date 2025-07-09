#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;
// best time to buy and sell stock

int bestTimeToBuySellStock(vector<int> prices) {
  int maxProfit = 0;
  int minPrice = INT_MAX;
  int n = prices.size();
  for (int i = 0; i < n; i++) {
    if (prices[i] < minPrice) {
      minPrice = prices[i];
    }
    int profit = prices[i] - minPrice;
    if (profit > maxProfit) {
      maxProfit = profit;
    }
  }
  return maxProfit;
}

int main() {

  vector<int> prices = {7, 1, 5, 3, 6, 4};
  cout << bestTimeToBuySellStock(prices) << endl;
  return 0;
}
