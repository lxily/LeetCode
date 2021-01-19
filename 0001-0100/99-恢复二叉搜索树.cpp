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
    #define inf 0x3f3f3f3f
    int preVal;
    TreeNode *preNode;
    vector<TreeNode*>v;
    void inorder(TreeNode* root){
        if(root==nullptr)return;
        inorder(root->left);
        if(preVal=-inf&&preVal>root->val){
            v.push_back(preNode);
            v.push_back(root);
        }
        preNode=root;
        preVal=root->val;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        preVal=-inf;
        inorder(root);
        if(v.size()==2)
            swap(v[0]->val,v[1]->val);
        else{
            swap(v[0]->val,v[3]->val);
        }
    }
};
int main(){
    return 0;
}
