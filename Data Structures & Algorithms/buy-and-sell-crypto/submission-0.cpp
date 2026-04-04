class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int c_max = 0;
        for(int l = 0; l < prices.size()-1; l++) {
            for(int r = l+1; r < prices.size(); r++) {
                if((r>l) && ((prices[r]-prices[l]) > c_max)) {
                    c_max = (prices[r]-prices[l]);
                }
                
            }
        }
        return c_max;
    }
};
