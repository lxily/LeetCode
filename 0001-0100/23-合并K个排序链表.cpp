#include<bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    struct cmp{
        bool operator () (const ListNode *N1,const ListNode *N2)const{
            return N1->val>N2->val;
        }
    };
    /*
    每个节点进一次堆以及出一次堆，复杂度O(nlogk)
    n为节点总数，k为链表数目
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>Q;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=nullptr)Q.push(lists[i]);
        }
        ListNode *ret=new ListNode(0);
        ListNode *head=ret;
        while(!Q.empty()){
            ListNode *out=Q.top();Q.pop();
            ret->next=new ListNode(out->val);
            if(out->next)Q.push(out->next);
            ret=ret->next;
        }
        return head->next;
    }
};
int main(){
    return 0;
}
