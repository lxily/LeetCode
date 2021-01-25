#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£º
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
