class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int num1;
        int num2;
        int result;
        for(int i = 0; i < tokens.size(); i++) {
            if((tokens[i] !="+") && (tokens[i] !="-") && (tokens[i] !="*") && (tokens[i] !="/")) {
                s.push(stoi(tokens[i]));
            }
            else if(tokens[i] == "+") {
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                result = num1+num2;
                s.push(result);
            }
            else if(tokens[i] == "-") {
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                result = num1-num2;
                s.push(result);
            }
            else if(tokens[i] == "*") {
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                result = num1*num2;
                s.push(result);
            }
            else {
                num2 = s.top();
                s.pop();
                num1 = s.top();
                s.pop();
                result = num1/num2;
                s.push(result);
            }
        }
        result = s.top();
        return result;
    }
};
