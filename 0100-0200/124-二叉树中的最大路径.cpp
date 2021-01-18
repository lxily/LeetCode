#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    #define inf 0x3f3f3f3f
    #define mkp(a,b) make_pair(a,b)
    #define piii pair<pair<int,int>,int>
    #define mxpiii(p) max(max(p.first.first,p.first.second),p.second)
    piii solve(TreeNode *root){
        if(!root->left&&!root->right)
            //从根出发，跨越根，不跨越根
            return mkp(mkp(root->val,root->val),root->val);
        piii pl,pr;
        if(root->left) pl=solve(root->left);
        if(root->right)pr=solve(root->right);
        if(root->left&&!root->right)
            return mkp(mkp(max(0,pl.first.first)+root->val,max(0,pl.first.first)+root->val),mxpiii(pl));
        if(root->right&&!root->left)
            return mkp(mkp(max(0,pr.first.first)+root->val,max(0,pr.first.first)+root->val),mxpiii(pr));
        return mkp(mkp(max(max(0,pl.first.first),pr.first.first)+root->val,max(0,pl.first.first)+max(0,pr.first.first)+root->val),max(mxpiii(pl),mxpiii(pr)));
    }
    int maxPathSum(TreeNode* root) {
        return mxpiii(solve(root));
    }
};
int main(){
    return 0;
}
