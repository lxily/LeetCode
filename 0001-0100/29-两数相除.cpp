#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1)
            return INT_MAX;
        int ret=0,i=1;
        int sgn1=dividend<0?-1:1;
        int sgn2=divisor<0?-1:1;
        if(dividend==INT_MIN){
            if(divisor==1)return INT_MIN;
            if(divisor==INT_MIN)return 1;
            dividend+=sgn2*divisor;ret++;
        }
        if(divisor==INT_MIN){
            return 0;
        }
        dividend=abs(dividend);
        divisor=abs(divisor);
        while(!((divisor>>30)&1)&&(divisor<<1)<dividend){
            divisor<<=1;i<<=1;
        }
        while(i>=1){
            while(dividend>=divisor){
                ret+=i;
                dividend-=divisor;
            }
            divisor>>=1;i>>=1;
        }
        return sgn1*sgn2*ret;
    }
}S;
int main(){
    cout<<S.divide(7,3)<<endl;
    return 0;
}
