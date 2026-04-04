class Solution {
public:
    int trap(vector<int>& height) {
        //calculate max heighths on left and right
        vector<int> l;
        vector<int> r;
        int current_max = 0;
        //calculate max on left
        for(int i = 0; i < height.size(); i++) {
            l.push_back(current_max);
            if(height[i] > current_max) {
                current_max = height[i];
            }
        }
        //calculate max on right
        current_max = 0;
        for(int i = height.size()-1; i >= 0; i--) {
            r.insert(r.begin(), current_max);
            if(height[i] > current_max) {
                current_max = height[i];
            }
        }
        //compute water height for each step
        vector<int> water_heights;
        for(int i = 0; i < height.size(); i++) {
            //min(l, r) - h[i]
            //TODO: fix below, need to calculate max heights on left and right
            int sum = std::min(l[i], r[i]);
            sum-=height[i];
            if(sum > 0) {
                water_heights.push_back(sum);
            }
            else {
                water_heights.push_back(0);
            }
        }
        //compute total areaa
        int c_area = 0;
        int f_area = 0;
        for(int i = 0; i < height.size(); i++) {
            if(water_heights[i] > 0) {
                c_area = c_area+water_heights[i];
            }
            else {
                c_area == 0;
            }
            if(c_area > f_area) {
                f_area = c_area;
            }
        }
        return f_area;
    }
};
