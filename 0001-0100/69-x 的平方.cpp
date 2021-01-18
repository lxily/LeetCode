#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
//        return floor(sqrt(x*1.0));
        int l=0,r=46340;
        while(l<r){
            int m=l+((r-l+1)>>1);
            if(m*m>x)r=m-1;
            else l=m;
        }
        return l;
    }
};
int main(){
    return 0;
}
