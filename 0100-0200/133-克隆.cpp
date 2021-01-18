#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    vector<Node*>vis;
    Solution(){
        vis.resize(101,0);
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        if(vis[node->val]){
            return vis[node->val];
        }
        Node *dst=new Node(node->val);
        vis[node->val]=dst;
        for(int i=0;i<node->neighbors.size();i++){
            dst->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return dst;
    }
};
int main(){
    return 0;
}
