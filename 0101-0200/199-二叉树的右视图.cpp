#include<bits/stdc++.h>
using namespace std;
/*
思路：层次遍历即可，每次先右后左，第一个即为每层右边第一个元素
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode *>Q;
        Q.push(root);
        vector<int>ret;
        while(!Q.empty()){
            ret.push_back(Q.front()->val);
            int sz=Q.size();
            for(int i=0;i<sz;i++){
                TreeNode *o=Q.front();Q.pop();
                if(o->right)Q.push(o->right);
                if(o->left)Q.push(o->left);
            }
        }
        return ret;
    }
};
//

int main(){
    return 0;
}
