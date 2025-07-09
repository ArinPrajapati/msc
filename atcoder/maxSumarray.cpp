#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSumArray(int n, vector<int> &arr) {
  int maxSum = arr[0];
  int currSum = arr[0];
  vector<int> ss = {arr[0]};
  vector<int> maxSubArray = {arr[0]};

  while (n--) {
    currSum += arr[n];
    ss.push_back(arr[n]);
    if (currSum < 0) {
      currSum = 0;
      ss.clear();
    }
    if (currSum > maxSum) {
      maxSum = currSum;
      maxSubArray = ss;
    }
  }

  for (int i = 0; i < maxSubArray.size(); i++) {
    cout << maxSubArray[i] << " ";
  }
  cout << endl;

  return maxSum;
}

int main() {
  int n = 5;
  vector<int> arr = {1, -2, 3, 4, -5};
  int result = maxSumArray(n, arr);
  cout << result << endl;
  return 0;
}
