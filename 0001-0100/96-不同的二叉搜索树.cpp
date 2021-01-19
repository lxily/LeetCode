#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int>ans(n+1,0);ans[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                ans[i]+=ans[j-1]*ans[i-j];
            }
        }
        return ans[n];
    }
};
/*
a[1] 1
a[2] (root=1)1+(root=2)1=2
a[3] (root=1)a[2]+(root==2)a[1]*a[1]+(root=3)a[2]=5
*/
int main(){
    return 0;
}
