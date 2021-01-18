#include<bits/stdc++.h>
using namespace std;
/*
思路：模拟找循环节即可
*/
//start here
class Solution {
public:
    #define ll long long
    string itos(ll num){
        if(num==0)return "0";
        string ret="";
        while(num){
            ret.push_back(num%10+'0');
            num/=10;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    string fractionToDecimal(int numerator, int denominator) {

        ll inside=numerator;
        ll outside=denominator;
        if(inside==0)return "0";

        //符号
        int sgn1=inside>0?1:-1;
        int sgn2=outside>0?1:-1;
        inside=abs(inside);
        outside=abs(outside);

        //整数部分
        ll preInt=inside/outside;
        inside%=outside;

        unordered_map<ll,int>mp;
        vector<ll>resultList;
        mp[inside]=0;
        int cycleIdx=-1;

        //小数部分
        for(;inside;){
            inside*=10;
            ll result=inside/outside;
            resultList.push_back(result);
            inside-=result*outside;
            if(mp.count(inside)){
                cycleIdx=mp[inside];
                break;
            }
            mp[inside]=resultList.size();
        }

        //整合结果
        string ret=(sgn1*sgn2<0?"-":"")+itos(preInt);
        if(resultList.size())ret.push_back('.');
        for(int i=0;i<resultList.size();++i){
            if(cycleIdx==i)ret.push_back('(');
            ret.push_back(resultList[i]+'0');
        }
        if(cycleIdx!=-1)ret.push_back(')');
        return ret;
    }
};
//

int main(){
    Solution solve;
    int x,y;
    while(cin>>x>>y){
        cout<<solve.fractionToDecimal(x,y)<<endl;
    }
    return 0;
}

