#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *help=new ListNode(0);
        ListNode *ret=help;
        help->next=head;
        while(head!=nullptr){
            ListNode *afterK=head;
            int cnt=k;
            while(afterK->next!=nullptr&&cnt>1){
                afterK=afterK->next;cnt--;
            }
            if(cnt==1){
                //head->nxt->nnxt->...
                ListNode *nxt=head->next;
                ListNode *nnxt=nxt->next;
                head->next=afterK->next;
                ListNode *preHead=head;
                for(int i=2;i<k;i++){
                    nxt->next=head;
                    head=nxt;
                    nxt=nnxt;
                    nnxt=nnxt->next;
                }
                nxt->next=head;
                help->next=afterK;
                help=preHead;
                head=help->next;
            }
            else break;
        }
        return ret->next;
    }
};
int main(){
    return 0;
}
