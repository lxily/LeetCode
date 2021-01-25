#include<bits/stdc++.h>
using namespace std;
/*
思路：记录路径，找分叉点
*/
//start here
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    unordered_map<TreeNode*,bool>mp;
    void search(TreeNode *root, TreeNode *p){
        if(!p)return;
        mp[root]=true;
        if(root==p)return;
        if(p->val<root->val)search(root->left,p);
        else                search(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, p);
        TreeNode *ret;
        do{
            ret=root;if(root==q)break;
            root=root->val>q->val?root->left:root->right;
        }while(mp[root]);
        return ret;
    }
};
//

int main(){
    return 0;
}
