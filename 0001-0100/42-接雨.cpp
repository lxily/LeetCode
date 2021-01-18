#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        height.push_back(0);
        height.insert(height.begin(),0);
        int sz=height.size();
        vector<int>lmx(sz,0);
        vector<int>rmx(sz,0);
        for(int i=1;i<sz-1;i++)
            lmx[i]=max(lmx[i-1],height[i]);
        for(int i=sz-2;i>0;i--)
            rmx[i]=max(rmx[i+1],height[i]);
        int ret=0;
        for(int i=1;i<sz-1;i++)
            ret+=min(lmx[i],rmx[i])-height[i];
        return ret;
    }
};
int main(){
    return 0;
}
