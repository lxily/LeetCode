#include<bits/stdc++.h>
using namespace std;
/*
˼·��˫ָ��ά��һ����ǡ�ô��ڵ���s�Ĵ���
*/
//start here
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l=0,r=0,sum=0,ans=INT_MAX;
        while(r<nums.size()){
            while(sum<s&&r<nums.size())sum+=nums[r++];
            while(sum>=s&&l<nums.size())sum-=nums[l++];
            if(l>0&&sum+nums[l-1]>=s)ans=min(ans,r-l+1);
        }
        return ans==INT_MAX?0:ans;
    }
};
//

int main(){
    return 0;
}
