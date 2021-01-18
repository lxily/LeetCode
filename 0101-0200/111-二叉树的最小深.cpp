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
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        if(!root->left&&!root->right)
            return 1;
        if(root->left&&root->right)
            return min(minDepth(root->left),minDepth(root->right))+1;
        if(root->left)
            return minDepth(root->left)+1;
        return minDepth(root->right)+1;
    }
};
int main(){
    return 0;
}
