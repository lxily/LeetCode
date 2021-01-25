#include<bits/stdc++.h>
using namespace std;
/*
思路：双端队列维护窗口中的单调队列，最大值即为当前窗口最大值
*/
//start here
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>mxValue;
        int n=nums.size();
        vector<int>ret;
        for(int i=0;i<n;i++){
            while(!mxValue.empty()&&mxValue.back()<nums[i])
                mxValue.pop_back();
            mxValue.push_back(nums[i]);
            if(i>=k&&mxValue.front()==nums[i-k])
                mxValue.pop_front();
            if(i>=k-1)ret.push_back(mxValue.front());
        }
        return ret;
    }
};
//

int main(){
    return 0;
}
