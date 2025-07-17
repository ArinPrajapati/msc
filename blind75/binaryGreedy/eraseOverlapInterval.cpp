#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int count = 0;
        // for minimum number of intervals to remove, we sort by the end time
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>&b){
            return a[1] < b[1];
        });

        vector<int> curr = intervals[0];
        int n = intervals.size();

        for(int i = 1;i < n;i++){
            if(intervals[i][0] < curr[1]){
                count++;
            }else{
                curr= intervals[i];
            }
        }
        


return count;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    int result = sol.eraseOverlapIntervals(intervals);
    cout << "Number of intervals to remove: " << result << endl;
    // Output the result
    return 0;
}
