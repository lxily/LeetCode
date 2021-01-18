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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>S;
        while(root!=nullptr){
            S.push(root);
            root=root->left;
        }
        while(!S.empty()){
            root=S.top();S.pop();
            ret.push_back(root->val);
            root=root->right;
            while(root!=nullptr){
                S.push(root);
                root=root->left;
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
