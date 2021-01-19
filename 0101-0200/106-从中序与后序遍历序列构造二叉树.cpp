#include<bits/stdc++.h>
using namespace std;
/*
思路：
*/
//start here
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
    vector<int>pre,ino;
    unordered_map<int,int>idxi;
    void record(){
        for(int i=0;i<ino.size();i++){
            idxi[ino[i]]=i;
        }
    }
    /*
    //前序+中序
    TreeNode* myBuildTree(int lp,int rp,int li,int ri){
        if(lp>rp)
            return nullptr;
        if(lp==rp)
            return new TreeNode(pre[lp]);
        TreeNode *root=new TreeNode(pre[lp]);
        //root:pre[lp]
        //root's pos of inorder: prt=ino[pre[lp]];  --- [li,prt-1] - [prt] - [prt+1,ri]
        //nodes of left is (prt-li), nodes of right is (ri-prt)
        //[lp] - [lp+1,lp+prt-li] - [lp+prt-li+1,rp]
        int prt=idxi[pre[lp]];
        root->left=myBuildTree(lp+1,lp+prt-li,li,prt-1);
        root->right=myBuildTree(lp+prt-li+1,rp,prt+1,ri);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())return nullptr;
        pre=preorder;ino=inorder;record();
        return myBuildTree(0,pre.size()-1,0,ino.size()-1);
    }
    */
    //中序+后序
    TreeNode* myBuildTree(int lp,int rp,int li,int ri){
        if(lp>rp)
            return nullptr;
        if(lp==rp)
            return new TreeNode(pre[rp]);
        TreeNode *root=new TreeNode(pre[rp]);
        //root:pre[rp]
        //root's pos of inorder: prt=idxi[pre[rp]];  --- [li,prt-1] - [prt] - [prt+1,ri]
        //nodes of left is (prt-li), nodes of right is (ri-prt)
        //[lp,lp+prt-li-1] - [lp+prt-li,rp-1] - [rp]
        int prt=idxi[pre[rp]];
        root->left=myBuildTree(lp,lp+prt-li-1,li,prt-1);
        root->right=myBuildTree(lp+prt-li,rp-1,prt+1,ri);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!postorder.size())return nullptr;
        pre=postorder;ino=inorder;record();
        return myBuildTree(0,pre.size()-1,0,ino.size()-1);
    }
};
//

int main(){
    return 0;
}

