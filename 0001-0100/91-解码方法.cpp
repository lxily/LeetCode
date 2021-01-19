#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size(),0);
        dp[0]=s[0]!='0';
        int len=s.length();
        for(int i=1;i<len;i++){
            if(s[i]!='0')
                dp[i]=dp[i-1];
            int val=s[i-1]-'0';
            val=val*10+s[i]-'0';
            if(s[i-1]!='0'&&val<=26&&val>0)
                dp[i]+=i-2>=0?dp[i-2]:1;
            else if(s[i]=='0')
                return 0;
        }
        return dp[len-1];
    }
};
int main(){
    return 0;
}
