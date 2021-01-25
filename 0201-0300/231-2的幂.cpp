#include<bits/stdc++.h>
using namespace std;
/*
思路：判断是否只存在一个1位->Brian Kernighan 算法清楚最末尾的1->判断结果是否为零
*/
//start here
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&!(n&n-1);
    }
};
//

int main(){
    return 0;
}
