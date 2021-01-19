#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int rev=0,y=x;
        while(x){
            int d=x%10;x/=10;
            if(rev>INT_MAX/10||(rev==INT_MAX/10&&d>7))
                return false;
            rev=rev*10+d;
        }
        return rev==y;
    }
};
int main(){
    return 0;
}
