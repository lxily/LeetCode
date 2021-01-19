#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        #define inf 0x3f3f3f3f
        if(!matrix.size())return {};
        vector<int>ret;
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0,x=0,y=-1;
        while(cnt!=n*m){
            while(y+1<m&&matrix[x][y+1]!=inf){
                ret.push_back(matrix[x][++y]);
                matrix[x][y]=inf;cnt++;
            }
            while(x+1<n&&matrix[x+1][y]!=inf){
                ret.push_back(matrix[++x][y]);
                matrix[x][y]=inf;cnt++;
            }
            while(y-1>=0&&matrix[x][y-1]!=inf){
                ret.push_back(matrix[x][--y]);
                matrix[x][y]=inf;cnt++;
            }
            while(x-1>=0&&matrix[x-1][y]!=inf){
                ret.push_back(matrix[--x][y]);
                matrix[x][y]=inf;cnt++;
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
