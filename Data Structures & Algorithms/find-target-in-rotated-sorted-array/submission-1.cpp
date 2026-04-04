class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start_p = 0;
        int end_p = nums.size()-1;
        while (start_p <= end_p) {
            if(nums[start_p] == target) {
                return start_p;
            }
            if(nums[end_p] == target) {
                return end_p;
            }
            int mid_p = (start_p + end_p)/2;
            if(nums[mid_p] == target) {
                return mid_p;
            }
            //determine which direction to search
            if(nums[mid_p] >= nums[start_p]) {
                //left half is sorted
                if (nums[start_p] <= target && target < nums[mid_p]) {
                    end_p = mid_p -1;
                }
                else {
                    start_p = mid_p + 1;
                }
            }
            else { //right half is sorted
                if (nums[mid_p] < target && target <= nums[end_p]) {
                    start_p = mid_p +1;
                }
                else {
                    end_p = mid_p - 1;
                }
            }
        }
        return -1;
    }
};
