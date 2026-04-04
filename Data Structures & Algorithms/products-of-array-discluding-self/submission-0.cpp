class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results;
        int product = 1;
        int prod_no_0 = 1;
        int zero_count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                prod_no_0 *= nums[i];
            }
            else {
                zero_count++;
            }
            product *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            if(zero_count >= 2) {
                results.push_back(0);
            }
            else {
                if(nums[i] == 0) {
                    results.push_back(prod_no_0);
                }
                else {
                    results.push_back(product/nums[i]);
                }
            }
        }
        return results;
    }
};
