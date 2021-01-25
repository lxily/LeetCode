#include<bits/stdc++.h>
using namespace std;
/*
思路：1、逐行二分O(nlogm)。2、总坐下或者右上角，每次判断可减少一行/一列的判断O(n+m);
*/
//start here
class Solution {
public:
    // O(nlogm)
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int n=matrix.size();
    //     int m=matrix[0].size();
    //     for(int i=0;i<n;i++){
    //         int l=0,r=m-1;
    //         while(l<r){
    //             int mid=l+((r-l+1)>>1);
    //             if(matrix[i][mid]<=target)l=mid;
    //             else                      r=mid-1;
    //         }
    //         if(matrix[i][l]==target)return true;
    //     }
    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        std::ios::sync_with_stdio(0);
        int n=matrix.size();
        int m=matrix[0].size();
        int row=n-1,col=0;
        while(row>=0&&col<m){
            if(matrix[row][col]==target)return true;
            if(target<matrix[row][col])--row;
            else                       ++col;
        }
        return false;
    }
};
//

int main(){
    return 0;
}
