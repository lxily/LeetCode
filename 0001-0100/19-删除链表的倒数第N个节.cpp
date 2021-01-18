#include<bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    pair<ListNode*,int> dfs(ListNode* head,int n){
        if(head==nullptr)return {nullptr,0};
        pair<ListNode*,int>p=dfs(head->next,n);
        if(p.second==n){//head后有n个节点
            head->next=head->next->next;
        }
        return make_pair(head,p.second+1);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* help=new ListNode(0);
        help->next=head;
        pair<ListNode*,int>p=dfs(help,n);
        return p.first->next;
    }
};
int main(){
    return 0;
}
