#include<vector>
#include<iostream>
using namespace std;

class solution {
private:

public:
    int numofunplacedfruits(vector<int>& fruits, vector<int>& baskets) {

      int n = fruits.size();
    int count = 0;
    vector<int> used(n, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          if (fruits[i] <= baskets[j] && !used[j]) {
              used[j] = 1;
              count++;
              break;
          }
      }
    }
      

     return n - count;
    }
};



int main(){
  solution s;
  vector<int> fruits = {4,2,5};
  vector<int> baskets = {3,5,4};

  int result = s.numofunplacedfruits(fruits, baskets);
  cout << "Number of unplaced fruits: " << result << endl;
  return 0;
}
