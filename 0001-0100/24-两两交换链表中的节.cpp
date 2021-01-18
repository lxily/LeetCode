#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)return head;
        ListNode *help=new ListNode(0);
        ListNode *ret=help;
        help->next=head;
        while(head->next!=nullptr){
            help->next=head->next;
            head->next=head->next->next;
            help->next->next=head;
            help=help->next->next;
            head=head->next;
            if(head==nullptr)break;
        }
        return ret->next;
    }
};
int main(){
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    S.swapPairs(head);
    return 0;
}
