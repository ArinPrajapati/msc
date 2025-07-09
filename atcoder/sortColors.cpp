#include <iostream>
#include <vector>

using namespace std;
// dutch national flag problem

vector<int> dutchFlag(vector<int> arr) {

  int l = 0; // 0
  int m = 0;
  int r = arr.size() - 1; // 2

  while (m <= r) {
    if (arr[m] == 2) {
      int temp = arr[r];
      arr[r] = arr[m];
      arr[m] = temp;
      r--;
    } else if (arr[m] == 0) {
      int temp = arr[l];
      arr[l] = arr[m];
      arr[m] = temp;
      l++;
      m++;
    } else {
      m++;
    }
  }

  return arr;
}

int main() {
  vector<int> arr = {2, 0, 2, 1, 1, 0};
  vector<int> sortedArr = dutchFlag(arr);
  for (int i : sortedArr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
