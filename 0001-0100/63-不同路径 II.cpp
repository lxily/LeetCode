#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1)
            return 0;
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        dp[1][1]=1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(i==1&&j==1||obstacleGrid[i-1][j-1])continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        return dp[m][n];
    }
};
int main(){
    return 0;
}
