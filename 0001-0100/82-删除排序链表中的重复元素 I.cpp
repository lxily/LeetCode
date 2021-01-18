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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *help=new ListNode(0x3f3f3f3f);
        ListNode *ret=help;help->next=head;
        int pre=0x3f3f3f3f;
        while(head){
            if(head->next==nullptr){
                if(head->val!=pre)
                    help->next=new ListNode(head->val);
            }
            else{
                if(head->val==head->next->val){
                    pre=head->val;
                }
                else{
                    if(head->val!=pre){
                        help->next=new ListNode(head->val);
                    }
                }
            }
            head=head->next;
            if(help->next)
                help=help->next;
        }
        return ret->next;
    }
};
int main(){
    return 0;
}
