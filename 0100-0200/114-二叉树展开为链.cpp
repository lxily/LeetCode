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
    TreeNode *solve(TreeNode *root){
        if(root==nullptr)return nullptr;
        TreeNode *lt=solve(root->left);
        TreeNode *rt=solve(root->right);
        if(!lt&&!rt)return root;
        if(lt){
            lt->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        return rt?rt:lt;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};
int main(){
    return 0;
}
