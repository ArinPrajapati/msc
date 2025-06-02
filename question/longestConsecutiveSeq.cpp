#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int> set;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }

        for (int i : set) {
            if (set.find(i - 1) == set.end()) {
                int j = i;
                int l = 0;
                while (set.find(j) != set.end()) {
                    l++;
                    j++;
                }
                maxlen = max(maxlen, l);
            }
            
        }
        return maxlen;
    }
};

int main() { return 0; }
