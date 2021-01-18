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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int>ret;
        stack<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            root=Q.top();Q.pop();
            ret.push_back(root->val);
            if(root->left)
                Q.push(root->left);
            if(root->right)
                Q.push(root->right);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
    return 0;
}
