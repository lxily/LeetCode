#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0)return {0};
        vector<int>ret={0,1};
        for(int i=1,inc=2;i<n;i++,inc<<=1){
            vector<int>tmp=ret;
            reverse(tmp.begin(),tmp.end());
            for(int j=0;j<tmp.size();j++)
                tmp[j]+=inc;
            ret.insert(ret.end(),tmp.begin(),tmp.end());
        }
        return ret;
    }
};
int main(){
    return 0;
}
