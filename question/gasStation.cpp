#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0;
    int n = gas.size();
    vector<int> diff(n, 0);
    int gt = 0;
    int ct = 0;
    for (int i = 0; i < n; i++) {
      diff[i] = gas[i] - cost[i];
      gt += gas[i];
      ct += cost[i];
    }
    if (gt >= ct) {
      return -1;
    }
    int pin = 0;
    for (int i = 0; i < n; i++) {
      if (total < 0) {
        total = 0;
        pin = i;
      }
      total += diff[i];
    }
    return pin;
  }
};

int main() {

  Solution sol;
  vector<int> gas = {1, 2, 3,};
  vector<int> cost = {3, 4, 5, };
  int result = sol.canCompleteCircuit(gas, cost);
  cout << "Starting point: " << result << endl;

  return 0;
}
