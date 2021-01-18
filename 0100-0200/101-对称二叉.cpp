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
    bool solve(TreeNode *pre,TreeNode *pos){
        if(pre==nullptr&&pos==nullptr)
            return true;
        if((pre!=nullptr)!=(pos!=nullptr))
            return false;
        if(pre->val!=pos->val)
            return false;
        solve(pre->left,pos->right);
        solve(pre->right,pos->left);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }
};
int main(){
    return 0;
}
