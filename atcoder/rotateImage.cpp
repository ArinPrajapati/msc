#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>> &image) {
  int n = image.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int temp = image[i][j];
      image[i][j] = image[j][i];
      image[j][i] = temp;
    }
  }
  for (auto &row : image) {
    reverse(row.begin(), row.end());
    cout << endl;
  };

  return image;
}

int main() {
  vector<vector<int>> image = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  vector<vector<int>> rotatedImage = rotateImage(image);
  for (const auto &row : rotatedImage) {
    for (const auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
