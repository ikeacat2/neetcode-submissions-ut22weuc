class Solution {
public:
    int findMin(vector<int> &nums) {
        /*
        int start_p = 0;
        int end_p = nums.size()-1;
        while(start_p != end_p) { 
            if(nums[start_p] > nums[start_p+1]) {
                return nums[start_p+1];
            }
            start_p++;
        }
        return nums[0];
        */
        //do binary search to create a O(logn) solution
        int start_p = 0;
        int end_p = nums.size()-1;
        int result = nums[0];
        while (start_p <= end_p) {
            if(nums[start_p] < nums[end_p]) {
                result = std::min(result, nums[start_p]);
                break;
            }
            int mid_p = (start_p + end_p)/2;
            result = std::min(result, nums[mid_p]);
            //determine which direction to search
            if(nums[mid_p] >= nums[start_p]) {
                //search right
                start_p = mid_p+1;
            }
            else { //search left
                end_p = mid_p-1;
            }
        }
        return result;
        
    }
};
