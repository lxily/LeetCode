#include<bits/stdc++.h>
using namespace std;
/*
思路：直接循环统计，或者折半统计个数（下述）
*/
//start here
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n=(n&0x55555555)+((n&0xAAAAAAAA)>>1);
        n=(n&0x33333333)+((n&0xCCCCCCCC)>>2);
        n=(n&0x0f0f0f0f)+((n&0xf0f0f0f0)>>4);
        n=(n&0x00ff00ff)+((n&0xff00ff00)>>8);
        n=(n&0x0000ffff)+((n&0xffff0000)>>16);
        return n;
    }
};
//

int main(){
    return 0;
}
