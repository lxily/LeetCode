#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if(!n)return 0;
        int m=matrix[0].size();
        int l=0,r=n*m-1;
        while(l<r){
            int md=(l+r)>>1;
            if(matrix[md/m][md%m]<target)
                l=m+1;
            else r=m;
        }
        return matrix[l/m][l%m]==target;
    }
};
int main(){
    return 0;
}
