#include<bits/stdc++.h>
using namespace std;
/*
˼·�������������k���ڵ��˳�����
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
    #define inf 0x3f3f3f3f
    int kthMin;
    Solution(){
        kthMin=0;
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)return -inf;
        int LValue=-inf,rValue=-inf;
        if(root->left)LValue=kthSmallest(root->left,k);
        if(LValue!=-inf)return LValue;//��߷����˵�kС
        kthMin++;if(kthMin==k)return root->val;//��ǰΪ��kС
        if(kthMin<k&&root->right)rValue=kthSmallest(root->right,k);//��kС���ұ�
        return rValue;
    }
};
//

int main(){
    return 0;
}
