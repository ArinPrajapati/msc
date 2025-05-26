#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      unordered_map<int, bool> row;
      unordered_map<int,bool> col;

     // map filler 
     for(size_t i = 0;i < matrix.size();i++){
        for(size_t j = 0;j < matrix[0].size();j++){
          if(matrix[i][j] == 0){
          row[i] = true;
          col[j] = true;
          }
        }
      }

    for(size_t i = 0;i< matrix.size();i++){
      for(size_t j = 0; j < matrix[0].size();j++){
        if(row[i]){
          matrix[i][j] = 0;
        }else if (col[j]) {
          matrix[i][j] = 0;
        }
      }
    }
    }
};

int main(){

  Solution s;
  vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
  s.setZeroes(m);
  return 0;
};
