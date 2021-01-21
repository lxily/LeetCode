#include<bits/stdc++.h>
using namespace std;
/*
思路：模拟，保留两个节点逐次翻转即可
递归的方法有点巧妙
*/
//start here
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* last=head;
        head=head->next;
        last->next=nullptr;
        while(head->next){
            ListNode* nxt=head->next;
            head->next=last;
            last=head;
            head=nxt;
        }
        head->next=last;
        return head;
    }
};
//

int main(){
    return 0;
}
