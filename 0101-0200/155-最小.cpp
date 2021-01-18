#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>all,_min;
    MinStack() {

    }

    void push(int x) {
        all.push(x);
        if(_min.empty()||x<=_min.top())
            _min.push(x);
    }

    void pop() {
        if(_min.top()==all.top())
            _min.pop();
        all.pop();
    }

    int top() {
        return all.top();
    }

    int getMin() {
        return _min.top();
    }
};
int main(){
    return 0;
}
