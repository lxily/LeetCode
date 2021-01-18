#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int total;
    vector<vector<bool>>vis;
    void solve(int row,int n){
        if(row==n){
            total++;
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[0][i]&&!vis[1][row+i]&&!vis[2][row-i+n]){
                vis[0][i]=vis[1][row+i]=vis[2][row-i+n]=true;
                solve(row+1,n);
                vis[0][i]=vis[1][row+i]=vis[2][row-i+n]=false;
            }
        }
    }
    int totalNQueens(int n) {
        total=0;
        vis.resize(3,vector<bool>(n*2+1,0));
        solve(0,n);
        return total;
    }
};
int main(){
    return 0;
}
