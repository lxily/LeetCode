#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<2)return;
        int l=0,r=nums.size()-1;
        while(l<r&&nums[l]==0)l++;//l���ȫΪ0
        while(r>l&&nums[r]==2)r--;//r�ұ�ȫΪ0
        for(int i=l;i<=r;i++){    //i�������
            if(nums[i]==2){
                if(r==i)r--;
                else swap(nums[i],nums[r--]);
            }
            if(nums[i]==0){
                if(l==i)l++;
                else swap(nums[i],nums[l++]);
            }
        }
    }
};
int main(){
    return 0;
}
