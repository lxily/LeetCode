#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n==m)return head;
        ListNode *help=new ListNode(-1);
        ListNode *ret=help;help->next=head;
        ListNode *pre=head,*lst=head;
        ListNode *ppre=help,*llst=head->next;
        int delta=n-m;
        for(int i=1;i<n;i++){
            if(i>=m){//·­×ª
                ListNode *nxt=llst->next;
                llst->next=lst;
                lst=llst;
                llst=nxt;
            }
            else{
                lst=lst->next;
                llst=llst->next;
            }
            if(i>delta){
                pre=pre->next;
                ppre=ppre->next;
            }
        }
        ppre->next=lst;
        pre->next=llst;
        return ret->next;
    }
};
int main(){
    return 0;
}
