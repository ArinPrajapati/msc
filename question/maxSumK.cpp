#include<bits/stdc++.h>
#include <vector>
using namespace std;


class Solution{

  public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {

     int n = nums1.size();
     vector<array<int,3>> arr;
      for(int i = 0; i < n; i++) {
        arr.push_back({nums1[i], nums2[i],i});
     }

    sort(arr.begin(),arr.end());


    priority_queue<int, vector<int>, greater<int>> pq;
    long long heapSum = 0;
    vector<long long> answer(n,0);

    for(int i = 0;i < n;i++){
            int val1 = arr[i][0];
      int val2 = arr[i][1];
      int idx = arr[i][2];

      answer[idx] = heapSum;
     
      if(i == 0) {
        pq.push(val2);
        heapSum += val2;
        if((int)pq.size() > k){
          heapSum -= pq.top();
          pq.pop();
        }
      }

      if(i > 0 && arr[i][0] == arr[i-1][0]) {
        pq.push(val2);
      heapSum += val2;

      if((int)pq.size() > k){
        heapSum -= pq.top();
        pq.pop();
      }

      }

      

    }
    return answer;
    };
};
