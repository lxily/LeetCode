#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>nums;
        while(head!=nullptr){
            nums.push_back(head->val);
            head=head->next;
        }
        return nums.size()?solve(nums,0,nums.size()-1):nullptr;
    }
};
int main(){
    return 0;
}
