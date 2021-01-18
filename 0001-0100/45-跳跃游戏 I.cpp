#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define inf 0x3f3f3f3f
    int jump(vector<int>& nums) {
        if(nums.size()<2)return 0;
        int sz=nums.size();
        int idx=nums[0],ret=1,i=1;
        while(i<sz){
            if(idx>=sz-1)break;
            int tmp=0;
            while(i<=idx){
                if(i+nums[i]>tmp)
                    tmp=i+nums[i];
            }
            ret++;
            idx=tmp;
        }
        return ret;
    }
};
int main(){
    return 0;
}
