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
    TreeNode* solve(vector<int>nums,int l,int r){
        if(l==r)return new TreeNode(nums[l]);
        int m=(l+r)>>1;
        TreeNode *root=new TreeNode(nums[m]);
        if(l<m)root->left=solve(nums,l,m-1);
        if(r>m)root->right=solve(nums,m+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return nums.size()?solve(nums,0,nums.size()-1):nullptr;
    }
};
int main(){
    return 0;
}
