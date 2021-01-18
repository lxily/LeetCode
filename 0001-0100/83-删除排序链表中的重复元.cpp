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
        ListNode *help=new ListNode(0x3f3f3f3ff);
        ListNode *ret=help;
        while(head!=nullptr){
            if(help->val!=head->val){
                help->next=new ListNode(head->val);
                help=help->next;
            }
            head=head->next;
        }
        return ret->next;
    }
};
int main(){
    return 0;
}
