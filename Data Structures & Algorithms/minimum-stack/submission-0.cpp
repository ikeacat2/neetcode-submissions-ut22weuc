#include <algorithm>
class MinStack {
private:
        vector<int> minstack;
        vector<int> s;
public:

    MinStack() {
        //implement with a sorted array
    }
    
    void push(int val) {
        s.push_back(val);
        if (minstack.empty() || val <= minstack.back()) {
            minstack.push_back(val);
        } else {
            minstack.push_back(minstack.back());
        }
    }
    
    void pop() {
        minstack.pop_back();
        s.pop_back();
    }
    int top() {
        return s.back();
    }
    
    int getMin() {
        return minstack.back();
    }
};
