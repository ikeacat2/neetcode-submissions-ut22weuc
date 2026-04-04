class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for(int i = 0; i < nums.size()-2; i++) {
            if((i > 0) && (nums[i] == nums[i-1])) {
                continue;
            }
            int l = i + 1;
            int r = nums.size()-1;
            while(l < r) {
                if((nums[i] + nums[r] + nums[l]) == 0) {
                    if((l == i+1) || (nums[l] != nums[l-1])){
                        results.push_back({nums[i], nums[l], nums[r]});
                    }
                    r--;
                    l++;
                }
                else if((nums[i] + nums[r] + nums[l]) < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return results;
    }
};
