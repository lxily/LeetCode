#include<bits/stdc++.h>
using namespace std;
/*
思路：很笨的做法，直接记录父节点，往上爬
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
    unordered_map<TreeNode*, TreeNode*>father;
    void getFather(TreeNode* root, TreeNode *fa){
        if(!root)return;
        father[root]=fa;
        getFather(root->left,root);
        getFather(root->right,root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        getFather(root,nullptr);
        unordered_map<TreeNode*,bool>mp;
        do{mp[p]=true;p=father[p];}while(p);
        while(!mp[q])q=father[q];
        return q;
    }
};
//

int main(){
    return 0;
}
