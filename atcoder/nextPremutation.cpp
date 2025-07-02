#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> nextPermutation(vector<int> arr) {
  int n = arr.size();
  int i = n - 2;
  while (i >= 0 && arr[i] >= arr[i + 1]) {
    i--;
  }

  if (i >= 0) {
    int j = n - 1;
    while (arr[j] <= arr[i]) {
      j--;
    }
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
  }
  reverse(arr.begin() + i + 1, arr.end());
  return arr;
};

int main() {

  vector<int> n = {1, 3, 2, 4};
  vector<int> s = nextPermutation(n);

  for (auto &i : s) {
    cout << i;
  }
  cout << endl;

  return 0;
}
