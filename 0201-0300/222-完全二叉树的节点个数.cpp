#include<bits/stdc++.h>
using namespace std;
/*
˼·����������...ֱ�ӱ���O(n)
�����������ֱȽ������������
һ���ǹٷ����Ķ���+��λ�жϽڵ��Ƿ����
��һ����������ȫ�������ĶԳ��ԣ����Ҹ߶���ͬ��������������ұ���
*/
//start here
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        return root?countNodes(root->left)+countNodes(root->right)+1:0;
    }
};
//

int main(){
    return 0;
}
