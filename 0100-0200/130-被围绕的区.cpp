#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& board){
        if(x<0||x>=board.size()||y<0||y>=board[x].size())return;
        if(board[x][y]!='O')return;
        board[x][y]='#';
        dfs(x-1,y,board);
        dfs(x+1,y,board);
        dfs(x,y-1,board);
        dfs(x,y+1,board);
    }
    void solve(vector<vector<char>>& board) {
        int sz=board.size();
        if(!sz)return;
        for(int i=0;i<board[0].size();i++)
            dfs(0,i,board);
        for(int i=0;i<board[sz-1].size();i++)
            dfs(sz-1,i,board);
        for(int i=0;i<board.size();i++)
            dfs(i,0,board);
        for(int i=0;i<board.size();i++)
            dfs(i,(int)board[i].size()-1,board);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!='X')
                    board[i][j]=board[i][j]=='#'?'O':'X';
            }
        }
    }
};
int main(){
    return 0;
}
