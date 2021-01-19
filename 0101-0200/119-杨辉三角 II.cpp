#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ret(2,vector<int>(rowIndex+1,0));
        int f=0;ret[0][0]=1;
        for(int i=1;i<=rowIndex;i++){
            ret[f^1][0]=1;
            for(int j=1;j<=i;j++)
                ret[f^1][j]=ret[f][j-1]+ret[f][j];
            f^=1;
        }
        return ret[f];
    }
};
int main(){
    return 0;
}
