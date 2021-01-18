#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return nullptr;
        if(mp.count(head))return mp[head];
        Node *dst=new Node(head->val);
        dst->next=copyRandomList(head->next);
        dst->random=copyRandomList(head->random);
        return mp[head]=dst;
    }
};
int main(){
    return 0;
}
