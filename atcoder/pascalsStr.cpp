#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cout << "Enter the number of rows for Pascal's Triangle: ";
  cin >> n;
  vector<vector<int>> triagle;
  for (int i = 0; i < n; ++i) {
    vector<int> row(i + 1, 1);
    int n = row.size();
    for (int j = 1; j < n - 1; ++j) {
      row[j] = triagle[i - 1][j] + triagle[i - 1][j - 1];
    }
    triagle.push_back(row);
  }

  for (const auto &row : triagle) {
    for (const auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}
