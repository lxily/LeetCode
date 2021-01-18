#include<bits/stdc++.h>
using namespace std;
/*
����˼·��
һ���ֱ��������������->�������ȶ���ֵ����->ͬʱ�ƶ�ֱ����ȣ�O(n), O(1)
�������˼·��A�˶��켣Ϊa+c+b��b�˶��켣Ϊb+c+a����ʱһ������
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

