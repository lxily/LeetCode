#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)return nullptr;
        ListNode *fast=head;
        ListNode *slow=head;
        while(true){
            if(fast->next==nullptr)
                return nullptr;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==nullptr)
                return nullptr;
            if(fast==slow)
                break;
        }
        while(head!=slow){
            head=head->next;
            slow=slow->next;
        }
        return head;
    }
};
int main(){
    return 0;
}
