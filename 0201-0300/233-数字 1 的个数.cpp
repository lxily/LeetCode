#include<bits/stdc++.h>
using namespace std;
/*
思路：找数字1出现的规律，从第位向高位递推
写完以后准备看数位dp的写法，一看题解，全是找规律...
*/
//start here
class Solution {
public:
    #define ll long long
    int countDigitOne(int n) {
        vector<ll>base={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
        ll ret=(n%10>=1);
        for(ll i=1,h=1,m=n/10,d=m%10;m;m/=10,d=m%10,h=h*10+base[i++]){
            ret=ret+d*h+(d>1?base[i]:d==1?n%base[i]+1:0);
        }
        return ret;
    }
};
//

int main(){
    return 0;
}
