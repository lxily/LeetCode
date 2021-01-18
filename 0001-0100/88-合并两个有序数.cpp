#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1=m-1,idx2=n-1,cnt=n+m;
        while(cnt--){
            if(idx1==-1)nums1[cnt]=nums2[idx2--];
            else if(idx2==-1)break;
            else if(nums1[idx1]>=nums2[idx2])
                nums1[cnt]=nums1[idx1--];
            else nums1[cnt]=nums2[idx2--];
        }
//        vector<int>ret;
//        while(idx1<m||idx2<n){
//            if(idx1==m||(idx2!=n&&nums1[idx1]>nums2[idx2]))
//                ret.push_back(nums2[idx2++]);
//            else if(idx2==n||(idx1!=m&&nums1[idx1]<=nums2[idx2]))
//                ret.push_back(nums1[idx1++]);
//        }
//        nums1=ret;
    }
};
int main(){
    return 0;
}
