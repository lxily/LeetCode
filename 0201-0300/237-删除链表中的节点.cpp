#include<bits/stdc++.h>
using namespace std;
/*
思路：直接用当前传入的节点替代下一个节点
*/
//start here
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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};
//

int main(){
    return 0;
}
