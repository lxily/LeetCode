#include<bits/stdc++.h>
using namespace std;
/*
˼·���ݹ飬�ڷ��صĹ������жϣ�ʱ�ո��ӵľ�ΪO(n)
�޸�����ɽ��Ϳռ临�Ӷ�ΪO(1)
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
    ListNode *front;
    bool dfs(ListNode *behind){
        if(!behind)return true;
        if(!dfs(behind->next))return false;
        if(front->val!=behind->val)return false;
        front=front->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        front=head;return dfs(head);
    }
};
//

int main(){
    return 0;
}
