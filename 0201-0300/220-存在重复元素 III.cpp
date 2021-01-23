#include<bits/stdc++.h>
using namespace std;
/*
思路：维护区间长度为k的所有数字，查找区间中是否有满足条件的值
      下方代码中multiset可换为set，有相同数字时直接为true
      题解的桶排序很妙
*/
//start here
class Solution {
public:
    #define ll long long
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<2||k<1)return false;
        multiset<ll>st;
        st.insert(nums[0]);
        int n=nums.size();
        k=min(k,n);
        for(int i=1;i<n;i++){
            multiset<ll>::iterator it=st.lower_bound(1ll*nums[i]-t);
            if(it!=st.end()&&*it<=1ll*nums[i]+t)return true;
            if(i>=k)st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
        }
        return false;
    }
};
//

int main(){
    return 0;
}
