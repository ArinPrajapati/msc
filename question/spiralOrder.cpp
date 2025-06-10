#include <ios>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> list;
    int t = 0;
    int b = matrix.size() - 1 ; int l = 0;
    int r = matrix[0].size() - 1;

    while(t <= b && l <= r){
      for(int i =0;i< r;i++){
        list.push_back(matrix[t][i]);
      }
      t++;
      for(int i = t;i < b;++i){
        list.push_back(matrix[i][r]);
      }
      r--;
      if(t <= b){
        for(int i = r ;i >= l;--i){
          list.push_back(matrix[b][i]);
        }
        b--;
      }

      if(l <= r){
        for(int i = b;i >= t;--i){
          list.push_back(matrix[i][l]);
        }
        l++;
      }
    }
    return list;
  }
  
};

int main() {}
