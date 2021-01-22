#include<bits/stdc++.h>
using namespace std;
/*
思路：有限队列（堆排序）维护最大的K个值
*/
//start here
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> >Q;
        for(int i=0;i<nums.size();i++){
            if(Q.size()<k||nums[i]>Q.top()){
                Q.push(nums[i]);
                if(Q.size()>k)Q.pop();
            }
        }
        return Q.top();
    }
};
//

int main(){
    return 0;
}
