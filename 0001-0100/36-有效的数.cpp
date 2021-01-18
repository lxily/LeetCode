#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<vector<int>>>grid(3,vector<vector<int>>(3,vector<int>(10,0)));
        for(int i=0;i<9;i++){
            vector<int>r(10,0);
            vector<int>c(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int d=board[i][j]-'0';
                    if(++r[d]>1||++grid[i/3][j/3][d]>1)return false;
                }
                if(board[j][i]!='.'){
                    int d=board[j][i]-'0';
                    if(++c[d]>1)return false;
                }
            }
        }
        return true;
    }
};
int main(){
    return 0;
}
