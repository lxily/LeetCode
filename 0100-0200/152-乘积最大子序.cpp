#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int product(vector<int>&nums,int l,int r){
        if(l>r)return INT_MIN;
        int ret=1;
        for(int i=l;i<=r;i++)
            ret*=nums[i];
        return ret;
    }
    int solve(vector<int>&nums,int l,int r){
        if(l>r)return INT_MIN;
        if(l==r)return nums[l];
        int neg=0,L=r,R=l;
        for(int i=l;i<=r;i++){
            if(nums[i]<0){
                neg++;
                L=min(L,i);
                R=max(R,i);
            }
        }
        if(neg&1)return max(product(nums,l,R-1),product(nums,L+1,r));
        else     return product(nums,l,r);
    }
    int maxProduct(vector<int>& nums) {
        int ret=INT_MIN;
        for(int i=0,l=0;i<nums.size();i++){
            if(!nums[i]||i==nums.size()-1){
                if(!nums[i])ret=max(0,ret);
                ret=max(ret,solve(nums,l,i-(nums[i]==0)));
                l=i+1;
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
