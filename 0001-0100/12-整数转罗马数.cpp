#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string dealq(int num){
        string ret="";
        num/=1000;
        for(int i=0;i<num;i++)
            ret.push_back('M');
        return ret;
    }
    string dealb(int num){
        string ret="";
        num=num%1000/100;
        if(num==9)return "CM";
        if(num==4)return "CD";
        if(num>4)ret+="D",num-=5;
        for(int i=0;i<num;i++)
            ret.push_back('C');
        return ret;
    }
    string deals(int num){
        string ret="";
        num=num%100/10;
        if(num==9)return "XC";
        if(num==4)return "XL";
        if(num>4)ret+="L",num-=5;
        for(int i=0;i<num;i++)
            ret.push_back('X');
        return ret;
    }
    string dealg(int num){
        string ret="";
        num=num%10;
        if(num==9)return "IX";
        if(num==4)return "IV";
        if(num>4)ret+="V",num-=5;
        for(int i=0;i<num;i++)
            ret.push_back('I');
        return ret;
    }
    string intToRoman(int num) {
        return dealq(num)+dealb(num)+deals(num)+dealg(num);
    }
};
int main(){
    return 0;
}
