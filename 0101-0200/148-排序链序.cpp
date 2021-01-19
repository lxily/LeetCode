#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeSort(ListNode* head){
        if(head==nullptr)return head;
        ListNode *fast=head->next,*slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=nullptr;
        ListNode *L=mergeSort(slow);
        ListNode *R=mergeSort(fast);
        ListNode *help=new ListNode(-1);
        ListNode *ret=help;
        while(L!=nullptr||R!=nullptr){
            if(L==nullptr||R!=nullptr&&R->val<L->val){
                help->next=R;
                R=R->next;
            }
            else{
                help->next=L;
                L=L->next;
            }
            help=help->next;
        }
        return ret->next;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
int main(){
    return 0;
}
