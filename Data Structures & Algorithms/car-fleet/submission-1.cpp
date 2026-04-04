class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        //compute the times;
        for(int i = 0; i < position.size(); i++) {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i], time});
        }
        //sort by position decreasing
        sort(cars.begin(), cars.end(), greater<>());
        stack<double> fleets;
        //processing
        for(auto& [p, t] : cars) {
            if(fleets.empty() || (t > fleets.top())) {
                fleets.push(t);
            }
        }
        return fleets.size();
    }
};
