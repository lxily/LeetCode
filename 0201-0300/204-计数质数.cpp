#include<bits/stdc++.h>
using namespace std;
/*
Ë¼Â·£ºÉ¸·¨O(nlogn)
*/
//start here
class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isPrime(n+1,true);
        for(int i=0;i<=n;)
            isPrime[i++]=false,
            isPrime[i++]=true;
        isPrime[1]=false;
        isPrime[2]=true;
        for(int i=3;i*i<=n;i++){
            if(isPrime[i])for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
            cnt+=isPrime[i];
        return cnt;
    }
};
//

int main(){
    return 0;
}
