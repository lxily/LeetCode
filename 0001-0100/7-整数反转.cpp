#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int ret=0,sgn=x<0?-1:1;
        if(x==INT_MIN)return 0;
        if(sgn==-1)x=-x;
        while(x){
            if(ret*10ll+x%10>INT_MAX)
                return 0;
            ret=ret*10+x%10;x/=10;
        }
        return sgn*ret;
    }
};
int main(){
    int x=2147483648;
    int y=-INT_MIN;
    cout<<x<<" "<<y<<endl;
    return 0;
}
