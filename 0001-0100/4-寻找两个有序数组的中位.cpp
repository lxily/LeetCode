#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1=nums1.size(),sz2=nums2.size();
        int kth=(sz1+sz2+1)>>1;
        //0<=idx<=sz1, 0<=kth-idx<=sz2
        //--> max(0,kth-sz2)<=idx<=min(kth,sz1);
        int lo=max(0,kth-sz2),hi=min(kth,sz1);
        while(lo<hi){
            int m=(lo+hi)>>1;
            if(nums2[kth-m-1]>nums1[m])
                lo=m+1;
            else
                hi=m;
        }
        int mx1=lo?nums1[lo-1]:INT_MIN;
        int mx2=kth-lo?nums2[kth-lo-1]:INT_MIN;
        int val=max(mx1,mx2);
        if((sz1+sz2)&1)return val;
        int mi1=lo<sz1?nums1[lo]:INT_MAX;
        int mi2=kth-lo<sz2?nums2[kth-lo]:INT_MAX;
        return (val+min(mi1,mi2))*0.5;
    }
};
int main(){
    return 0;
}
