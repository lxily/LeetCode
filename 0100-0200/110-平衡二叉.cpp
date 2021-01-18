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
    pair<int,bool> solve(TreeNode *root){
        if(root==nullptr)return {0,true};
        pair<int,bool>lt=solve(root->left);
        pair<int,bool>rt=solve(root->right);
        if(lt.second==false||rt.second==false||
           abs(lt.first-rt.first)>1)
            return {0,false};
        return {max(lt.first,rt.first)+1,true};
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
int main(){
    return 0;
}
