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
    void solve(vector<vector<int>>&ret,TreeNode *root,int sum,vector<int>&now){
        if(root->left==nullptr&&root->right==nullptr){
            if(root->val==sum){
                now.push_back(root->val);
                ret.push_back(now);
                now.pop_back();
            }
            return;
        }
        now.push_back(root->val);
        if(root->left){
            solve(ret,root->left,sum-root->val,now);
        }
        if(root->right){
            solve(ret,root->right,sum-root->val,now);
        }
        now.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>tmp;
        vector<vector<int>>ret;
        if(root==nullptr)return {};
        solve(ret,root,sum,tmp);
        return ret;
    }
};
int main(){
    return 0;
}
