#include<bits/stdc++.h>
using namespace std;
/*
思路：模拟找连续区间即可
*/
//start here
class Solution {
public:
    #define ll long long
    string itos(ll x){
        int sgn=x<0?-1:1;
        x=abs(x);
        string ret=x?"":"0";
        while(x){
            ret.push_back(x%10+'0');
            x/=10;
        }
        reverse(ret.begin(),ret.end());
        return sgn<0?"-"+ret:ret;
    }
    void addInterval(vector<string>&ret,int l,int r){
        if(l==r)
            ret.push_back(itos(l));
        else
            ret.push_back(itos(l)+"->"+itos(r));
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ret;
        int l=-1;
        for(int i=0;i<nums.size();i++){
            if(l==-1){l=0;continue;}
            if(nums[i]!=nums[i-1]+1){
               addInterval(ret,nums[l],nums[i-1]);l=i;
            }
        }
        if(l!=-1)addInterval(ret,nums[l],nums[(int)nums.size()-1]);
        return ret;
    }
};
//

int main(){
    return 0;
}
