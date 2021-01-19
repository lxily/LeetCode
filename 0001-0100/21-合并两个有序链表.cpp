#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    #define inf 0x3f3f3f3f
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr&&l2==nullptr)return nullptr;
        int v1=inf,v2=inf;
        if(l1!=nullptr)v1=l1->val;
        if(l2!=nullptr)v2=l2->val;
        if(v1<v2)l1=l1->next;
        else     l2=l2->next;
        ListNode *ret=new ListNode(v1<v2?v1:v2);
        ListNode *head=ret;
        while(l1||l2){
            if(l1==nullptr||l1&&l2&&l1->val>=l2->val){
                ret->next=new ListNode(l2->val);
                l2=l2->next;
            }
            else if(l2==nullptr||l1&&l2&&l1->val<l2->val){
                ret->next=new ListNode(l1->val);
                l1=l1->next;
            }
            ret=ret->next;
        }
        return head;
    }
};
int main(){
    return 0;
}
