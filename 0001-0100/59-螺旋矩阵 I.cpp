#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int cnt=1,x=0,y=-1;
        while(cnt<=n*n){
            while(y+1<n&&!matrix[x][y+1]){
                matrix[x][++y]=cnt++;
            }
            while(x+1<n&&!matrix[x+1][y]){
                matrix[++x][y]=cnt++;
            }
            while(y-1>=0&&!matrix[x][y-1]){
                matrix[x][--y]=cnt++;
            }
            while(x-1>=0&&!matrix[x-1][y]){
                matrix[--x][y]=cnt++;
            }
        }
        return matrix;
    }
};
int main(){
    return 0;
}
