#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<bool>>vis;
    bool solve(vector<vector<char>>& board, string word,int p,int x,int y){
        if(p==word.size())return true;
        if(x<0||x>=board.size())return false;
        if(y<0||y>=board[x].size())return false;
        if(vis[x][y])return false;
        if(word[p]!=board[x][y])return false;
        board[x][y]=0;
        if(solve(board,word,p+1,x+1,y)||
           solve(board,word,p+1,x-1,y)||
           solve(board,word,p+1,x,y+1)||
           solve(board,word,p+1,x,y-1))
           return true;
        board[x][y]=word[p];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++)
                if(solve(board,word,0,i,j))
                    return true;
        }
        return false;
    }
};
int main(){
    return 0;
}
