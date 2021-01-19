#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ret="";
        if(a.size()<b.size())
            swap(a,b);
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int la=a.size(),lb=b.size();
        for(int i=0;i<la-lb;i++)
            b.push_back('0');
        int x=0;
        for(int i=0;i<la;i++){
            int da=a[i]-'0';
            int db=b[i]-'0';
            ret.push_back((da+db+x)%2+'0');
            x=(da+db+x)>1;
        }
        if(x)ret.push_back('1');
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
int main(){
    return 0;
}
