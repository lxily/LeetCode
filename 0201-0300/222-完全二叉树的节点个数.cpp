#include<bits/stdc++.h>
using namespace std;
/*
思路：笨逼做法...直接遍历O(n)
评论区有两种比较巧妙的做法，
一种是官方题解的二分+按位判断节点是否存在
另一种是利用完全二叉树的对称性，左右高度相同则左边满，否则右边满
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
    int countNodes(TreeNode* root) {
        return root?countNodes(root->left)+countNodes(root->right)+1:0;
    }
};
//

int main(){
    return 0;
}
