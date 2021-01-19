#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ret=0,i=0,l=s.length();
        //Ç§
        while(i<l&&s[i]=='M')ret+=1000,i++;
        //°Ù
        if(i<l&&s[i]=='C'&&i+1<l&&s[i+1]=='M'){
            ret+=900;i+=2;
        }
        if(i<l&&s[i]=='C'&&i+1<l&&s[i+1]=='D'){
            ret+=400;i+=2;
        }
        if(i<l&&s[i]=='D'){
            ret+=500;i++;
        }
        while(i<l&&s[i]=='C'){
            ret+=100;i++;
        }
        //Ê®
        if(i<l&&s[i]=='X'&&i+1<l&&s[i+1]=='C'){
            ret+=90;i+=2;
        }
        if(i<l&&s[i]=='X'&&i+1<l&&s[i+1]=='L'){
            ret+=40;i+=2;
        }
        if(i<l&&s[i]=='L'){
            ret+=50;i++;
        }
        while(i<l&&s[i]=='X'){
            ret+=10;i++;
        }
        //¸ö
        if(i<l&&s[i]=='I'&&i+1<l&&s[i+1]=='X'){
            ret+=9;i+=2;
        }
        if(i<l&&s[i]=='I'&&i+1<l&&s[i+1]=='V'){
            ret+=4;i+=2;
        }
        if(i<l&&s[i]=='V'){
            ret+=5;i++;
        }
        while(i<l&&s[i]=='I'){
            ret+=1;i++;
        }
        return ret;
    }
};
int main(){
    return 0;
}
