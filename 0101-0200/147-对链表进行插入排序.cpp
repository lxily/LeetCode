#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* help=new ListNode(INT_MIN);
        help->next=head;
        ListNode* tail=head;
        ListNode* now=head->next;
        /*
            head->(A)->(B)->tail->now->
        */
        while(now!=nullptr){
            ListNode* tmp=help;
            while(tmp->val<now->val&&tmp->next){
                tmp=tmp->next;
            }
            tail->next=now->next;
            now->next=tmp->next;
            tmp->next=now;
            now=tail->next;
        }
        return help->next;
    }
};
int main(){
    return 0;
}
