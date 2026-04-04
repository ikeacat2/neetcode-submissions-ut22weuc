class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results;
        int currentDays = 0;
        
        for(int i = 0; i < temperatures.size()-1; i++) {
            int currentTemp = temperatures[i];
            int currentDays = 0;
            bool found = false;
            for(int j = i+1; j < temperatures.size(); j++) {
                if(temperatures[j] > temperatures[i]) {
                    results.push_back(currentDays+1);
                    found = true;
                    break;
                }
                else {
                    currentDays++;
                }
            }
            if(!found) {
                results.push_back(0);
            }
        }
        results.push_back(0);
        return results;
    }
};
