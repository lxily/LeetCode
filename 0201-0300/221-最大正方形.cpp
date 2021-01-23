#include<bits/stdc++.h>
using namespace std;
/*
思路：动态规划，以[i,j]为右下角的最大正方形由[i-1,j-1]转移得到
*/
//start here
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(!n)return 0;
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            matrix[i].insert(matrix[i].begin(),'0');
        }
        matrix.insert(matrix.begin(),vector<char>(m+1,'0'));
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<vector<int>>up(n+1,vector<int>(m+1,0));
        vector<vector<int>>lt(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(matrix[i][j]=='1'){
                    up[i][j]=up[i-1][j]+1;lt[i][j]=lt[i][j-1]+1;
                    dp[i][j]=min(min(up[i-1][j],lt[i][j-1]),dp[i-1][j-1])+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};
//

int main(){
    return 0;
}
