#include<bits/stdc++.h>
using namespace std;
/*
˼·���ж�[n,m]���ֵ������У�ÿһλ�Ƿ���ֹ�0
      ��iλ��0ÿ��(1<<i)��������һ�Σ�����������(1<<i)��
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
