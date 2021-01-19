#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        double ret=1.0;
        if(n==INT_MIN){
            ret=x;n++;
        }
        int sgn=n<0?-1:1;
        n=abs(n);
        while(n){
            if(n&1)ret=ret*x;
            x*=2;n>>=1;
        }
        return sgn<0?1.0/ret:ret;
    }
};
int main(){
    return 0;
}
