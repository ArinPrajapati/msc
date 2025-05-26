#include <bits/stdc++.h>
#include <vector>

using namespace std;

void applyRangeUpdates(vector<int> &arr,
                       vector<tuple<int, int, int>> &updates) {
  int n = arr.size();
  vector<int> diff(n + 1, 0);

  cout << "Initial array: ";
  for (int x : arr)
    cout << x << " ";
  cout << "\n";

  // Apply each range update to the difference array
  cout << "\nApplying updates to the difference array:\n";
  for (auto &[l, r, val] : updates) {
    cout << "Add " << val << " from index " << l << " to " << r << "\n";
    diff[l] += val;
    if (r + 1 < n) {
      diff[r + 1] -= val;
      cout << "  diff[" << l << "] += " << val << ", diff[" << r + 1
           << "] -= " << val << "\n";
    } else {
      cout << "  diff[" << l << "] += " << val
           << " (no subtraction since r+1 >= n)\n";
    }
  }

  cout << "\nDifference array after all updates:\n";
  for (int i = 0; i < n; i++) {
    cout << diff[i] << " ";
  }
  cout << "\n";

  arr[0] = diff[0];
  for (int i = 1; i < n; i++) {
    arr[i] = arr[i - 1] + diff[i];
  }

  cout << "\nFinal array after applying all range updates:\n";
  for (int x : arr)
    cout << x << " ";
  cout << "\n";
}

int main() {

  vector<int> arr= {2,3,2,4,2}; // [0, 0, 0, 0, 0]
  vector<tuple<int, int, int>> updates = {
      {1, 3, 5}, // Add 5 to indices 1 to 3
      {2, 4, 2}  // Add 2 to indices 2 to 4
  };

  applyRangeUpdates(arr, updates);

  return 0;
}
