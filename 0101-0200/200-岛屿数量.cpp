#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
*/
//start here
class Solution {
public:
    int n,m;
    vector<vector<char>> _grid;
    void dfs(int x,int y){
        if(x<0||x>=_grid.size()||
           y<0||y>=_grid[x].size()||
           !(_grid[x][y]-'0'))return;
        _grid[x][y]='0';
        dfs(x+1,y);dfs(x-1,y);
        dfs(x,y+1);dfs(x,y-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;_grid=grid;
        for(int i=0;i<_grid.size();i++){
            for(int j=0;j<_grid[i].size();j++){
                if(_grid[i][j]-'0')dfs(i,j),ans++;
            }
        }
        return ans;
    }
};
//

int main(){
    return 0;
}
