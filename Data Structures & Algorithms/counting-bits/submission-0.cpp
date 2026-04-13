class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results;
        //every possible number including n
        for(int i = 0; i <= n; i++) {
            int count = 0;
            int x = i;
            while(x) {
                if(x%2 == 1) {
                    count++;
                }
                //x = x shifted right one bit
                x >>= 1;
            }
            results.push_back(count);
        }
        return results;
    }
};
