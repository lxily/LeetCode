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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)return false;
        if(root->left==nullptr&&root->right==nullptr)
            return root->val==sum;
        return (root->left?hasPathSum(root->left,sum-root->val):0)|
               (root->right?hasPathSum(root->right,sum-root->val):0);
    }
};
int main(){
    return 0;
}
