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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>Q;
        while(root){
            ret.push_back(root->val);
            Q.push(root);
            root=root->left;
        }
        while(!Q.empty()){
            root=Q.top();Q.pop();
            root=root->right;
            while(root){
                ret.push_back(root->val);
                Q.push(root);
                root=root->left;
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
