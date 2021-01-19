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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1=l1,*h2=l2;
        int x=h1->val+h2->val,c=0;
        c=x>=10;h1=h1->next;h2=h2->next;
        ListNode *newlist=new ListNode(x%10);
        ListNode *newhead=newlist;
        while(h1||h2){
            int x=0;
            if(h1)x+=h1->val,h1=h1->next;
            if(h2)x+=h2->val,h2=h2->next;
            newhead->next=new ListNode(x%10);
            c=x>=10;newhead=newhead->next;
        }
        if(c)newhead->next=new ListNode(c);
        return newlist;
    }
};
int main(){
    return 0;
}
