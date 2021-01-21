#include<bits/stdc++.h>
using namespace std;
/*
思路：判断[n,m]出现的数字中，每一位是否出现过0
      第i位的0每隔(1<<i)个数出现一次，并连续出现(1<<i)次
*/
//start here
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans=(n==m)&&(m&1);
        for(int i=1;i<32;i++){
            int bit=(m>>i)&1;
            if(!bit)continue;
            bit&=n-m+1<=(1<<i)-(m&(1<<i)-1);
            ans|=bit<<i;
        }
        return ans;
    }
};
//

int main(){
    return 0;
}
