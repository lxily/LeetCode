#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,ret=0;
        while(l<r){
            ret=max(ret,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r])l++;
            else r--;
        }
        return ret;
    }
}S;
int main(){
    vector<int>v={1,8,6,2,5,4,8,3,7};
    cout<<S.maxArea(v)<<endl;
    return 0;
}
