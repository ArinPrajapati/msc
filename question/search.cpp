#include<bits/stdc++.h>


using namespace std;

class Solution {
private:
  int modtifedBS(vector<int> arr,int target,int left,int right){
    cout<< "left" << left << "right" << right << endl;
    if(left > right){
      return -1;
    }

    int mid = left + (right - left) / 2;

    if(arr[mid] == target){
      return mid;
    }
    
    if(arr[mid] >= arr[left]){
      

      if(arr[left] <= target && target <= arr[mid]){
        return modtifedBS(arr,target,left,mid - 1);
      }else{
        return modtifedBS(arr,target, mid+1,right);
      }
    }else{
      if(arr[mid] <= target && target <= arr[right]){
        return modtifedBS(arr,target, mid + 1,right);
      }else{
        return modtifedBS(arr,target,left,mid -1);
      }
    }
  };
public:
    int search(vector<int>& nums, int target) {
      return modtifedBS(nums,target,0, nums.size() - 1);
    }
};


int main(){
  vector<int> d = {4,5,6,7,0,1,2};
  Solution s;
  cout << s.search(d,2);
  return 0;
}
