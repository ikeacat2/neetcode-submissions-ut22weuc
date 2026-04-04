class Solution {
public:
    bool isPalindrome(string s) {
        string alpha = "";
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                alpha += tolower(s[i]);
            }
        }
        int left = 0;
        int right = alpha.size()-1;
        while(left<right){
            if(alpha[right] != alpha[left]) {
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
};
