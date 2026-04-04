class Solution {
public:
    int findMin(vector<int> &nums) {
        int start_p = 0;
        int end_p = nums.size()-1;
        while(start_p != end_p) { //change this condition
            if(nums[start_p] > nums[start_p+1]) {
                return nums[start_p+1];
            }
            start_p++;
        }
        return nums[0];
    }
};
