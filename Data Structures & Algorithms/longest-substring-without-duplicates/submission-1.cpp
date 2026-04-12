class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        set<char> t;
        int max = 1;
        int h1 = 0;
        int h2 = 1;
        int current_max = 0;
        t.insert(s[h1]);
        while(h2 < s.size()) {
            while(t.contains(s[h2])) {
                t.erase(s[h1]);
                h1++;
            }
            current_max = h2-h1+1;
            t.insert(s[h2]);
            h2++;
            
            if(current_max > max) {
                max = current_max;
            }
        }
        return max;
    }
};
