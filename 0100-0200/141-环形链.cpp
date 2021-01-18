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
    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
        ListNode *fast=head;
        ListNode *slow=head;
        while(true){
            if(fast->next==nullptr)
                return false;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==nullptr)
                return false;
            if(fast==slow)
                return true;
        }
        return false;
    }
};
int main(){
    return 0;
}
