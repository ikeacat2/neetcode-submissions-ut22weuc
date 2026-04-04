class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s; //index, height pairs
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            int start = i;
            while(!s.empty() && s.top().second > heights[i]) {
                auto [index, height] = s.top();
                s.pop();
                maxArea = std::max(maxArea, height * (i-index));
                start = index;
            }
            s.push({start, heights[i]});
        }
        while(!s.empty()) {
            auto [index, height] = s.top();
            s.pop();
            maxArea = std::max(maxArea, height * (int)(heights.size() - index));
        }

        return maxArea;
    }
};
