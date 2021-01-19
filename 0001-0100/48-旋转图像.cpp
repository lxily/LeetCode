#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz=matrix.size();
        for(int i=0;i<sz/2;i++){
            for(int j=0;j<sz-i-1;j++){
                int idx=i,idy=j;
                for(int k=0;k<4;k++){
                    int nxtx=idy,nxty=sz-idx-1;
                    int val=matrix[nxtx][nxty];
                    matrix[nxtx][nxty]=matrix[i][j];
                    idx=nxtx;idy=nxty;
                }
            }
        }
    }
};
/*
0 1 2
3 4 5
6 7 8
        (i,j)
          1  2  3  4 (j,sz-i-1)
          5  6  7  8
          9  10 11 12
(sz-j-1,i)13 14 15 16
             (sz-i-1,sz-j-1)
*/
int main(){
    return 0;
}
