#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string cancleSpace(string s){
        int len=s.length();
        int l=0,r=len-1;
        while(l<len&&s[l]==' ')l++;
        while(r>=0&&s[r]==' ')r--;
        string ret="";
        for(int i=l;i<=r;i++)
            ret.push_back(s[i]);
        return ret;
    }
    bool existAlphaExceptValidCharacter(string &s){
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='E')s[i]+=32;
            if(s[i]=='e'||s[i]=='+'||s[i]=='-'||(s[i]>='0'&&s[i]<='9')||s[i]=='.')
                continue;
            return true;
        }
        return false;
    }
    int countDot(string s){
        int ret=0,len=s.length();
        for(int i=0;i<len;i++)
            ret+=s[i]=='.';
        return ret;
    }
    int countE(string s){
        int ret=0,len=s.length();
        for(int i=0;i<len;i++)
            ret+=s[i]=='e';
        return ret;
    }
    bool isAllDigit(string s){
        if(!s.size())return false;
        int len=s.length();
        for(int i=0;i<len;i++)
            if(s[i]<'0'||s[i]>'9')return false;
        return true;
    }
    bool isAnInteger(string s){
        if(!s.size())return false;
        int len=s.length(),i=0;
        if(len==1){
            return s[0]>='0'&&s[i]<='9';
        }
        if(s[0]=='+'||s[i]=='-')i++;
        return isAllDigit(s.substr(i,len));

    }
    bool checkNumber(string s){
        if(!s.size())return false;
        int dotCnt=countDot(s);
        if(dotCnt>1)return false;
        if(dotCnt==1){
            int idx=s.find('.');
            string pre=s.substr(0,idx);
            string lst=s.substr(idx+1,s.length());
            if(!pre.size()&&!lst.size()) //only '.'
                return false;
            if(!pre.size())
                return isAllDigit(lst);  // .123
            if(!lst.size())
                return isAnInteger(pre); //123.
            return (pre=="+"||pre=="-"||isAnInteger(pre))&&isAllDigit(lst);//+(123).345
        }
        return isAnInteger(s);
    }
    bool isNumber(string s) {
        s=cancleSpace(s);
        if(!s.size())return false;
        if(existAlphaExceptValidCharacter(s))return false;
        int eCnt=countE(s);
        if(eCnt>1)return false;
        if(eCnt==1){
            int idx=s.find('e');
            return checkNumber(s.substr(0,idx))&&
                   isAnInteger(s.substr(idx+1,s.length()));
        }
        return checkNumber(s);
    }
}S;
int main(){
    freopen("in.txt","r",stdin);
    string s="e";
    double x=99e5;
    while(getline(cin,s)){
        cout<<"\""<<s<<"\""<<" --> "<<(S.isNumber(s)?"True":"False")<<endl;
    }
    return 0;
}
