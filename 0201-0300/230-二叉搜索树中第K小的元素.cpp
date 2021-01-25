#include<bits/stdc++.h>
using namespace std;
/*
思路：中序遍历到第k个节点退出即可
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
        if(LValue!=-inf)return LValue;//左边返回了第k小
        kthMin++;if(kthMin==k)return root->val;//当前为第k小
        if(kthMin<k&&root->right)rValue=kthSmallest(root->right,k);//第k小在右边
        return rValue;
    }
};
//

int main(){
    return 0;
}
