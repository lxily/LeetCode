#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *>Q;
        if(root)Q.push(root);
        while(!Q.empty()){
            for(int i=0,sz=Q.size();i<sz;i++){
                Node *l=Q.front();Q.pop();
                if(i!=sz-1)l->next=Q.front();
                if(l->left)Q.push(l->left);
                if(l->right)Q.push(l->right);
            }
        }
        return root;
    }
};
int main(){
    return 0;
}
