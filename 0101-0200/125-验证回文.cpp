#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidChar(char &ch){
        if(ch>='A'&&ch<='Z')ch+=32;
        return ch>='a'&&ch<='z'||ch>='0'&&ch<='9';
    }
    bool isPalindrome(string s) {
        if(!s.size())return true;
        int l=0,r=s.size()-1;
        while(l<=r){
            while(l<=r&&!isValidChar(s[l]))l++;
            while(r>=l&&!isValidChar(s[r]))r--;
            if(l<=r&&s[l++]!=s[r--])return false;
        }
        return true;
    }
};
int main(){
    return 0;
}
