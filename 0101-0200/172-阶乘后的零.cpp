#include<bits/stdc++.h>
using namespace std;
/*
思路：统计5及其倍数出现的次数--一定有其余数与其相乘得到末尾零
*/
//start here
class Solution {
public:
    int trailingZeroes(int n) {
        int ret=0;
        for(long long d=5;d<=n; ret+=n/d,d*=5);
        return ret;
    }
};
//

int main(){
    return 0;
}

