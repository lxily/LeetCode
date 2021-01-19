#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(!n)return 0;
        for(int i=0;i<n;i++)
            matrix[i].push_back('0');
        int m=matrix[0].size();
        if(!m)return 0;
        vector<vector<int>>height(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')continue;
                height[i][j]=1;
                if(i-1>=0)height[i][j]+=height[i-1][j];
            }
        }
        int ret=0;
        for(int i=0;i<n;i++){
            stack<int>S;
            for(int j=0;j<m;j++){
                while(!S.empty()&&height[j]<=height[S.top()]){
                    int idx=S.top();S.pop();
                    int p=S.empty()?-1:S.top();
                    ret=max(ret,(j-p-1)*height[i][idx]);
                }
                S.push(j);
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
