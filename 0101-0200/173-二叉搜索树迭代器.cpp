#include<bits/stdc++.h>
using namespace std;
/*
˼·��Դ�����������Ϊ�����˼�룬����һ������������õ������ҪO(n)�ռ�
      ��ʵ���ϲ���Ҫһ�εõ������ά��һ�����������½ڵ��ջ����
      ÿ���ڵ������һ��ջ����̯���Ӷ�ΪO(1),ջ���Ϊ���߶�
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

