#include<bits/stdc++.h>
using namespace std;
/*
˼·��������ջģ�⣬���ݴ�һ��ջ��������Ƕ��е�˳���ٴ�����һ��ջ���ɣ�����ά������ջ
*/
//start here
class MyQueue {
public:
    stack<int>stk;
    stack<int>que;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!que.size())while(stk.size()){
            que.push(stk.top());
            stk.pop();
        }
        int ret=que.top();
        que.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        int ret=pop();
        que.push(ret);
        return ret;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return que.empty()&&stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//

int main(){
    return 0;
}
