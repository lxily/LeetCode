#include<bits/stdc++.h>
using namespace std;
/*
思路：记录前缀与后缀乘积，其中一个改为迭代计算可降低额外空间消耗至O(1)
*/
//start here
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ret;
        int n=(int)nums.size();
        for(int i=0,prod=1;i<n;i++){
            ret.push_back(prod);
            prod*=nums[i];
        }
        for(int i=n-1,prod=1;i>=0;i--){
            ret[i]=ret[i]*prod;
            prod*=nums[i];
        }
        return ret;
    }
};
//

int main(){
    return 0;
}
