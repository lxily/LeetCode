#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *help1=new ListNode(-1);
        ListNode *help2=new ListNode(-1);
        ListNode *ret=help1;
        while(head!=nullptr){
            if(head->val<x)
                help1->next=new ListNode(head->val),
                help1=help1->next;
            else
                help2->next=new ListNode(head->val),
                help2=help2->next;
        }
        help1->next=help2->next;
        return ret;
    }
};
int main(){
    return 0;
}
