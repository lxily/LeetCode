#include<bits/stdc++.h>
using namespace std;
/*
思路：记忆化模拟即可
*/
//start here
class Solution {
public:
    bool isHappy(int n) {
        vector<bool>v(1001,false);
        if(n<1001)v[n]=true;
        while(n!=1){
            int nxt=0;
            while(n){
                nxt+=(n%10)*(n%10);
                n/=10;
            }
            if(v[nxt])return false;
            v[n=nxt]=true;
        }
        return true;
    }
};
//

int main(){
    return 0;
}
