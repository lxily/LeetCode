#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        string last;
        stringstream in(s);
        while(in>>last);
        return last.length();
    }
};
int main(){
    return 0;
}
