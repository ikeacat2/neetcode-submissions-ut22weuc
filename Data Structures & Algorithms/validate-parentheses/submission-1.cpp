#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> cstack;
        if((s.size()%2) != 0) {
            return false;
        }
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                cstack.push(s[i]);
            }
            else if (s[i] == '}') {
                if(cstack.empty()) {
                    return false;
                }
                if (cstack.top() != '{') {
                    return false;
                }
                cstack.pop();
            }
            else if (s[i] == ')') {
                if(cstack.empty()) {
                    return false;
                }
                if (cstack.top() != '(') {
                    return false;
                }
                cstack.pop();
            }
            else {
                if(cstack.empty()) {
                    return false;
                }
                if (cstack.top() != '[') {
                    return false;
                }
                cstack.pop();
            }
        }
        if(cstack.empty()) {
            return true;
        }
        return false;
    }
};
