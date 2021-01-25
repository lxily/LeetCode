#include<bits/stdc++.h>
using namespace std;
/*
思路：Boyer-Moore投票算法
*/
//start here
class Solution {
public:
    bool check(const vector<int>& nums, int val){
        int cnt=0;
        for(int i=0;i<nums.size();i++)
            cnt+=nums[i]==val;
        return cnt>nums.size()/3;

    }
    vector<int> majorityElement(vector<int>& nums) {
        int nx=0,cx=0,ny=0,cy=0;
        for(int i=0;i<nums.size();i++){
            if((!cx||(nx==nums[i]))&&ny!=nums[i]){
                cx++;nx=nums[i];
            }
            else if(!cy||(ny==nums[i])){
                cy++;ny=nums[i];
            }
            else{
                cx--;cy--;
            }
        }
        vector<int>ret;
        if(cx&&check(nums,nx))ret.push_back(nx);
        if(cy&&check(nums,ny))ret.push_back(ny);
        return ret;
    }
};
//

int main(){
    return 0;
}
