#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int c_max = 0;
        for(int l = 0; l < heights.size()-1; l++) {
            for(int r = l+1; r < heights.size(); r++) {
                if(((r-l) * std::min(heights[l], heights[r])) > c_max) {
                    c_max = ((r-l) * std::min(heights[l], heights[r]));
                }
                
            }
        }
        return c_max;
    }
};
