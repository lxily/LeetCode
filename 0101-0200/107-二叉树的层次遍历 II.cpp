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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*>Q;
        vector<vector<int>>ret;
        Q.push(root);
        vector<int>tmp;
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
            ret.push_back(tmp);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
    return 0;
}
