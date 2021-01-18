#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*>nd;
        while(head!=nullptr){
            nd.push_back(head);
            head=head->next;
        }
        int l=0,r=(int)nd.size()-1;
        while(l<r){
            nd[l++]->next=nd[r];
            if(l==r){
                nd[r]->next=nullptr;
                break;
            }
            nd[r--]->next=nd[l];
            if(l==r){
                nd[l]->next=nullptr;
                break;
            }
        }
    }
};
int main(){
    return 0;
}
