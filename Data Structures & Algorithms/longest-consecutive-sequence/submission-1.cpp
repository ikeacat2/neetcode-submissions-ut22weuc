#include <map>
#include <algorithm>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if(nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        map<int, int> m;
        int j = 0;
        m[j] = 1;
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                continue;
            }
            if(nums[i] != (nums[i-1]+1)) {
                j++;
                m[j] = 1;
            }
            else {
                m[j]++;
            }
            
        }
        int max = 0;
        for(int i = 0; i < m.size(); i++) {
            if(m[i] > max) {
                max = m[i];
            }
        }
        return max;
    }
};
