#include <iostream>
#include <ostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){


//  int arr[5] = {1, 3, 4, 42, 4};

  //for(int i =0;i < 5;i++){
   // cin >> arr[i];
  //}


//  cout << endl;

//  arr[3] = 10;
  //for(int i = 0;i < 5;i++){
 //   cout << arr[i] << " " << endl;
 // }

/*
  int sum = 10;
  for(int i = 0; i < 5;i++){
    sum += arr[i];
  }
  cout << " Sum = " << sum << endl;


  for(int i = 0; i < 5/ 2 ; i++ ){
    swap(arr[i], arr[5-i-1]);
  }

  int maxVal = arr[0] , minVal = arr[0];

  for (int i = 1; i < 5;i++){
    maxVal = max(maxVal,arr[i]);
    minVal = min(minVal,arr[i]);
  }

  cout << "max " << maxVal << endl;
  cout << "min " << minVal << endl;

  sort(arr,arr+5);


*/


  vector<int> v;

  v.push_back(10);
  v.push_back(20);

  for(int i = 0;i < v.size();i++){
    cout << v[i] << " ";
  }
  return 0;
}



