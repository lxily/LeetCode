#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ret;
        vector<int>tmp;
        for(int i=0;i<numRows;i++){
            tmp.push_back(1);
            for(int j=1;j<=i;j++)
                tmp.push_back(ret[i-1][j-1]+(j==i?0:ret[i-1][j]));
            ret.push_back(tmp);
            tmp.clear();
        }
        return ret;
    }
};
int main(){
    return 0;
}
