#include <unordered_map>

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> elements;
        vector<int> final;

        for(int i = 0; i < nums.size(); i++) {
            elements[nums[i]]++;
        }

        vector<pair<int, int>> sorted_elements(elements.begin(), elements.end());
        sort(sorted_elements.begin(), sorted_elements.end(), compare);

        for(int i = 0; i < k; i++) {
            final.push_back(sorted_elements[i].first);
        }
        return final;
    }
};