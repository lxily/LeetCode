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
    int getLength(ListNode *head){
        return head==nullptr?0:getLength(head->next)+1;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len=getLength(head);
        if(len==0)return head;
        k%=len;if(k==0)return head;
        int delta=len-k;
        ListNode *tail=head;
        ListNode *phead=head;
        for(int i=0;tail->next;i++){
            tail=tail->next;
            if(i>=k)phead=phead->next;
        }
        ListNode *ret=phead->next;
        phead->next=nullptr;
        tail->next=head;
        return ret;
    }
};
int main(){
    return 0;
}
