#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumberK(vector<int>&nums,int k){
        vector<int>bit(k+1);
        for(int i=0;i<nums.size();i++){
            int tmp=~bit[1]&bit[k]&nums[i];
            for(int j=k;k>1;k--){
                bit[j]=~bit[j]&bit[j-1]&nums[i];
            }
            bit[1]=tmp;
        }
        return bit[1];
    }
    int singleNumber(vector<int>& nums) {
        return singleNumberK(nums,3);
    }
};
int main(){
    return 0;
}
