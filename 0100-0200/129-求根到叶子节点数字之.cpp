#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void solve(TreeNode *root,int now,int &ret){
        if(root==nullptr)return;
        now=now*10+root->val;
        if(!root->left&&!root->right)ret+=now;
        if(root->left)solve(root->left,now,ret);
        if(root->right)solve(root->right,now,ret);
    }
    int sumNumbers(TreeNode* root) {
        int ret=0;
        solve(root,0,ret);
        return ret;
    }
};
int main(){
    return 0;
}
