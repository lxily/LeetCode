#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<bool>>r,c;
    vector<vector<vector<bool>>>grid;
    bool dfs(vector<vector<char>>& board,int idx){
        if(idx==81)return true;
        int R=idx/9,C=idx%9,lo=1,hi=9;
        if(board[R][C]!='.')lo=hi=board[R][C]-'0';
        char prech=board[R][C];
        for(int i=lo;i<=hi;i++){
            if(prech!='.'||!r[R][i]&&!c[C][i]&&!grid[R/3][C/3][i]){
                r[R][i]=c[C][i]=grid[R/3][C/3][i]=true;
                board[R][C]='0'+i;
                if(dfs(board,idx+1))return true;
                board[R][C]=prech;
                if(prech=='.')r[R][i]=c[C][i]=grid[R/3][C/3][i]=false;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        r.resize(9,vector<bool>(10,0));
        c.resize(9,vector<bool>(10,0));
        grid.resize(3,vector<vector<bool>>(3,vector<bool>(10)));
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)
            if(board[i][j]!='.'){
            int d=board[i][j]-'0';
            r[i][d]=c[j][d]=grid[i/3][j/3][d]=true;
        }
        dfs(board,0);
    }
}S;
int main(){
    vector<vector<char>>b={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    S.solveSudoku(b);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
