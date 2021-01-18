#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz=nums.size();
        if(sz<2)return;
        int i=sz-2,j=sz-1,k=sz-1;
        while(i>=0&&nums[i]>=nums[j]){//Ñ°ÕÒÉÏÆÂ--
            --i;--j;
        }
        while(i>=0&&k>=0&&nums[i]>=nums[k]){
            --k;
        }
        if(i>=0&&k>=0)swap(nums[i],nums[k]);
        reverse(nums.begin()+i+1,nums.end());
    }
};
int main(){
    return 0;
}
/*
1 2 3 4 5
1 2 3 5 4
1 2 4 3 5
1 2 4 5 3
1 2 5 3 4
1 2 5 4 3
 /\
/  \
    \
*/
