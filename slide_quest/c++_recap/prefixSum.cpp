#include <iostream>
#include <iterator>
#include <vector>

int main(){

  std::vector<int> a= {2,4,1,3,7};
  std::vector<int> prefix(a.size());

  prefix[0] = a[0];

  for (size_t i = 1; i < a.size();i++){
    prefix[i] = prefix[i - 1] + a[i];
  }

  int l = 1 , r = 3 ; 
  int sum = prefix[r] - (l > 0? prefix[l - 1]:0);
  std::cout << l << " to " << r << " " << sum << std::endl;
}
