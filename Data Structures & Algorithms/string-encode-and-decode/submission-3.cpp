class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(int i = 0; i < strs.size(); i++) {
            encoded_string = encoded_string + strs[i] + "/n";
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int first = 0;
        int second = 0;
        while(second < s.size()) {
            if(s.substr(second, 2) == "/n") {
                strs.push_back(s.substr(first, (second-first)));
                first = second+2;
                second++;
            }
            second++;
        }
        return strs;
    }
};
