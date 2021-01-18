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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)return true;
        if(p->left==nullptr^q->left==nullptr)
            return false;
        if(p->right!=nullptr^q->right==nullptr)
            return false;
        if(p->left!=nullptr)
            return isSameTree(p->left,q->left);
        if(p->right!=nullptr)
            return isSameTree(p->right,q->right);
    }
};
int main(){
    return 0;
}
