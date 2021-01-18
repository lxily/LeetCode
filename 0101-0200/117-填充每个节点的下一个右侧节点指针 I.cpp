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
        for(Node *cur=root,*pre=nullptr,*firstNode=nullptr;cur;){
            if(cur->left){
                if(pre){pre->next=cur->left;}
                pre=cur->left;
            }
            if(cur->right){
                if(pre){pre->next=cur->right;}
                pre=cur->right;
            }
            if(firstNode==nullptr&&(cur->left||cur->right))
                firstNode=cur->left?cur->left:cur->right;

            if(cur->next)cur=cur->next;
            else{cur=firstNode;pre=firstNode=nullptr;}
        }
        return root;
    }
};
int main(){
    return 0;
}
