#include<bits/stdc++.h>
using namespace std;
/*
思路：源于中序遍历即为排序的思想，但是一次性中序遍历得到结果需要O(n)空间
      而实际上不需要一次得到结果，维护一个保存最左下节点的栈即可
      每个节点均进出一次栈，均摊复杂度为O(1),栈深度为树高度
*/
//start here
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *>S;
    BSTIterator(TreeNode* root) {
        if(root){
            S.push(root);
            while(S.top()->left){
                S.push(S.top()->left);
            }
        }

    }

    int next() {
        TreeNode *out=S.top();S.pop();
        TreeNode *add=out->right;
        while(add){
            S.push(add);
            add=add->left;
        }
        return out->val;
    }

    bool hasNext() {
        return !S.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//

int main(){
    return 0;
}

