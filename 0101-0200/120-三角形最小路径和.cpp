#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
*/
//start here
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz=triangle.size()-1;
        for(register int i=sz-1;i>=0;--i)
            for(register int j=0;j<=i;++j)
                triangle[i][j]+=triangle[i+1][j]>triangle[i+1][j+1]?triangle[i+1][j+1]:triangle[i+1][j];
        return triangle[0][0];
    }
};
//

int main(){
    return 0;
}

