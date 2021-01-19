#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>S;int ret=0;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!S.empty()&&heights[S.top()]>=heights[i]){
                int idx=S.top();S.pop();
                int p=S.empty()?-1:S.top();
                ret=max(ret,(i-p-1)*heights[idx]);
            }
            S.push(i);
        }
        return ret;
    }
}S;
int main(){
    vector<int>v={10,10,10,10,10};
    cout<<S.largestRectangleArea(v);
    return 0;
}
