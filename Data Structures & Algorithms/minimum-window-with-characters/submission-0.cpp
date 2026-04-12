class Solution {
public:
    string minWindow(string s, string t) {
        //impossible for s to contain t
        if(s.size() < t.size()) {
            return "";
        }
        //find alphabetic makeup of t 
        vector<int> freq(128,0);
        for(char c : t) {
            freq[c]++;
        }
        //now compare substrings of s to find this
        int p1 = 0;
        int p2 = 0;
        string substr = "";
        int required = t.size();
        while(p2 < s.size()){
            if(freq[s[p2]] > 0) {
                required--;
            }
            freq[s[p2]]--;
            while(required == 0) {
                string current = s.substr(p1, p2-p1+1);
               if((substr.size() == 0) || (current.size() < substr.size())) {
                substr = current;
               }
               freq[s[p1]]++;
               if(freq[s[p1]] > 0) {
                required++;
               }
               p1++;
            }
            p2++;

        }

        return substr;
    }
};
