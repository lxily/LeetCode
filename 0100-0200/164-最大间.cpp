#include<bits/stdc++.h>
using namespace std;
/*
鸽巢原理：
用N-2个点将线段划分为N-1段，所有段中的最大长度不会小于L/(N-1)--取上整;
*/
//start here
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int sz=nums.size();
        long long _max=-1e18;
        long long _min=1e18;
        for(int i=0;i<sz;++i){
            _max=max(_max,(long long)nums[i]);
            _min=min(_min,(long long)nums[i]);
        }
        if(!sz||_max==_min)return 0;
        int bucketSize=max(1ll,(_max-_min)/(sz-1));
        int bucketCnt=ceil(1.0*(_max-_min+1)/bucketSize);

        vector<long long>mx(bucketCnt,-1e18);
        vector<long long>mi(bucketCnt,1e18);

        for(int i=0;i<sz;++i){
            int idx=ceil(1.0*(nums[i]-_min+1)/bucketSize)-1;
            mx[idx]=max(mx[idx],(long long)nums[i]);
            mi[idx]=min(mi[idx],(long long)nums[i]);
        }
        long long ret=0,preMax=mx[0];
        for(int i=1;i<bucketCnt;++i){
            if(mi[i]!=1e18){
                ret=max(ret,mi[i]-preMax);
                preMax=mx[i];
            }
        }
        return ret;
    }
};
//

int main(){
    return 0;
}

