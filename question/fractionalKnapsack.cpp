#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) { return a[1] > b[1]; }

double factionalKnapaact(vector<vector<int>> &items, int capacity) {
  sort(items.begin(), items.end(), compare);
  double totalValue = 0.0;
  for (auto &item : items) {
    if (capacity >= item[1]) {
      totalValue += item[0];
      capacity -= item[1];
    } else {
      totalValue += (static_cast<double>(item[0]) / item[1]) * capacity;
      break;
    }
  }
  return totalValue;
}

int main() {
  vector<vector<int>> items = {{60, 10}, {100, 20}, {120, 30}};
  int capacity = 50;
  double maxValue = factionalKnapaact(items, capacity);
  cout << "Maximum value in Knapsack = " << maxValue << endl;
  return 0;
}
