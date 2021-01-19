#include<bits/stdc++.h>
using namespace std;
/*
思路：二分判断初始值是否可行，时间复杂度O(N^2logN)
题解：倒序dp(很好理解)，正序的dp很麻烦，时间复杂度O(N^2)
*/
//start here
class Solution {
public:
    bool solve(vector<vector<int>> dungeon,int init){
        dungeon[0][0]+=init;
        int n=dungeon.size();
        int m=dungeon[0].size();
        for(int i=1;i<m;i++){
            if(dungeon[0][i-1]>0)
                dungeon[0][i]+=dungeon[0][i-1];
            else
                dungeon[0][i]=-1;
        }
        for(int i=1;i<n;i++){
            if(dungeon[i-1][0]>0)
                dungeon[i][0]+=dungeon[i-1][0];
            else
                dungeon[i][0]=-1;
        }
        for(int i=1;i<n;i++)for(int j=1;j<m;j++){
            if(dungeon[i-1][j]<=0&&dungeon[i][j-1]<=0)
                dungeon[i][j]=-1;
            else if(dungeon[i-1][j]>0&&dungeon[i][j-1]>0)
                dungeon[i][j]+=max(dungeon[i-1][j],dungeon[i][j-1]);
            else if(dungeon[i-1][j]>0)
                dungeon[i][j]+=dungeon[i-1][j];
            else
                dungeon[i][j]+=dungeon[i][j-1];
        }
        return dungeon[n-1][m-1]>0;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l=1,r=INT_MAX/2-1;
        while(l<r){
            int m=(l+r)>>1;
            if(solve(dungeon,m)){
                r=m;
            }
            else l=m+1;
        }
        return l;
    }
};
//

int main(){
    return 0;
}

