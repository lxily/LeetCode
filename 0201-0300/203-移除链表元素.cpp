#include<bits/stdc++.h>
using namespace std;
/*
思路：模拟，遍历时保留前一个指针
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=nullptr&&head->val==val)head=head->next;
        if(head==nullptr)return head;
        ListNode* iterPre=head;
        ListNode* iter=head->next;
        while(iter!=nullptr){
            if(iter->val==val){
                iterPre->next=iter->next;
                iter=iterPre->next;
            }
            else{
                iter=iter->next;
                iterPre=iterPre->next;
            }
        }
        return head;
    }
};
//

int main(){
    return 0;
}
