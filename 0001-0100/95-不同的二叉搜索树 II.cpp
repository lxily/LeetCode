#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> solve(vector<int>nums){
        vector<TreeNode*>ret;
        if(!nums.size())return {nullptr};
        vector<int>lt,rt;
        for(int i=0;i<nums.size();i++){
            lt.clear();rt.clear();
            for(int j=0;j<i;j++)
                lt.push_back(nums[j]);
            for(int j=i+1;j<nums.size();j++)
                rt.push_back(nums[j]);
            vector<TreeNode*>lret=solve(lt);
            vector<TreeNode*>rret=solve(rt);
            for(int j=0;j<lret.size();j++){
                for(int k=0;k<rret.size();k++){
                    TreeNode *T=new TreeNode(nums[i]);
                    T->left=lret[j];
                    T->right=rret[k];
                    ret.push_back(T);
                }
            }
        }
        return ret;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n)return{};
        vector<int>nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        return solve(nums);
    }
};
int main(){
    return 0;
}
