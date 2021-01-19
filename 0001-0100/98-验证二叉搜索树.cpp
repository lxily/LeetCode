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
    #define mkp(a,b) make_pair(a,b)
    #define piii pair<pair<int,int>,int>//最大值、最小值、是否合法
    piii validBST(TreeNode *root){
        if(root==nullptr)
            return mkp(mkp(-inf,inf),1);//1-空树，-1不合法，2-合法

        piii pl=validBST(root->left);
        piii pr=validBST(root->right);
        int ls=pl.second;
        int rs=pr.second;
        if(ls==-1||rs==-1)
            return mkp(mkp(-inf,inf),-1);
        if(ls!=1&&pl.first.first>=root->val||
           rs!=1&&pr.first.second<=root->val)
            return mkp(mkp(-inf,inf),-1);
        int maxVal=root->val;
        int minVal=root->val;
        if(rs!=1)maxVal=max(maxVal,pr.first.first);
        if(ls!=1)minVal=min(minVal,pl.first.second);
        return mkp(mkp(maxVal,minVal),2);
    }
    bool isValidBST(TreeNode* root) {
        return validBST(root).second!=-1;
    }
};
int main(){
    return 0;
}
