class Solution {
public:
    int characterReplacement(string s, int k) {
        if((s.size() < 2) || (k >= s.size())) {
            return s.size();
        }

        //frequency count 
        vector<int> freq(26, 0);
        int left = 0;
        int result = 0;
        int freq_max = 0;
        for(int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            freq_max = std::max(freq_max, freq[s[right] - 'A']);
            while((right-left+1) - freq_max > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};
