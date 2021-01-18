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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*>Q;
        vector<vector<int>>ret;
        Q.push(root);
        vector<int>tmp;
        int f=0;
        while(!Q.empty()){
            tmp.clear();
            int sz=Q.size();
            for(int i=0;i<sz;i++){
                tmp.push_back(Q.front()->val);
                if(Q.front()->left)
                    Q.push(Q.front()->left);
                if(Q.front()->right)
                    Q.push(Q.front()->right);
                Q.pop();
            }
            if(f)reverse(tmp.begin(),tmp.end());
            ret.push_back(tmp);f^=1;
        }
        return ret;
    }
};
int main(){
    return 0;
}
