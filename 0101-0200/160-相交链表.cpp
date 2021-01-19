#include<bits/stdc++.h>
using namespace std;
/*
两种思路：
一：分别计算两条链表长度->长链表先动差值步数->同时移动直到相等；O(n), O(1)
二：题解思路，A运动轨迹为a+c+b，b运动轨迹为b+c+a，此时一定相遇
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *Ha=headA;
        ListNode *Hb=headB;
        while(headA!=headB){
            headA=headA==NULL?Hb:headA->next;
            headB=headB==NULL?Ha:headB->next;
        }
        return headA;
    }
};
//


int main(){
    return 0;
}

