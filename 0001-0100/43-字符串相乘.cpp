#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int sz1=num1.size();
        int sz2=num2.size();
        vector<int>res(sz1+sz2+1,0);
        for(int i=sz1-1;i>=0;i--){
            for(int j=sz2-1;j>=0;j--){
                int d1=num1[i]-'0';
                int d2=num2[j]-'0';
                res[(sz1-i-1)+(sz2-j-1)]+=d1*d2;
            }
        }
        for(int i=0;i<res.size()-1;i++){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
        string ret="";
        int i=sz1+sz2;
        while(!res[i])i--;
        if(i<0)return "0";
        while(i>=0)ret.push_back('0'+res[i]);
        return ret;
    }
};
int main(){
    return 0;
}
