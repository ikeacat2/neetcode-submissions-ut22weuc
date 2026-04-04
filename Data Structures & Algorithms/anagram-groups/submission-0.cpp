#include <map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sort all the strings
        std::map<string, vector<string>> results;
        for(string& s: strs) {
            std::string count(26, 0); //vector of 26 0s, a... zaligna
            for(char& c : s) {
                count[int(c) - int('a')] += 1;
            }
            results[count].push_back(s);
        }
        std::vector<vector<string>> final;
        for(auto& pair : results) {
            final.push_back(pair.second);
        }
        return final;
        //O(m * n) solution
    }
};
