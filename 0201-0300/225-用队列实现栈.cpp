#include<bits/stdc++.h>
using namespace std;
/*
˼·��pop()->ѭ��ֱ���������һ��Ԫ��,top()->�õ����һ��Ԫ�ز��Ż�
*/
//start here
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int>Q;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int sz=Q.size();
        for(int i=1;i<Q.size();i++){
            Q.push(Q.front());Q.pop();
        }
        int ret=Q.front();Q.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        int ret=pop();
        Q.push(ret);
        return ret;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//

int main(){
    return 0;
}
