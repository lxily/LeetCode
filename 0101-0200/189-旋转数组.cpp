#include<bits/stdc++.h>
using namespace std;
/*
思路：循环交换（需要一定的推理过程）
题解中三次翻转很巧妙
*/
//start here
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();k%=n;
        if(!n||!k)return;
        int cycleCnt=__gcd(n,k);
        for(int i=0;i<cycleCnt;i++){
            int aimIdx=(i+k)%n;
            do{
                swap(nums[i],nums[aimIdx]);
                aimIdx=(aimIdx+k)%n;
            }while(aimIdx!=i);
        }
    }
};
//

int main(){
    return 0;
}

