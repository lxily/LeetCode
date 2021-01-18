#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fac[10];
    Solution(){
        fac[0]=1;for(int i=1;i<10;i++)fac[i]=fac[i-1]*i;
    }
    string getPermutation(int n, int k) {
        vector<bool>used(n+1,0);
        string ret="";
        for(int i=n;i>=1;i--){
            int kth=k/fac[i-1];
            kth+=k%fac[i-1]!=0;
            k-=(kth-1)*fac[i-1];
            for(int cnt=0,j=1;j<=n;j++){
                if(!used[j]&&kth==++cnt){
                    ret.push_back(j+'0');
                    used[j]=true;break;
                }
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
