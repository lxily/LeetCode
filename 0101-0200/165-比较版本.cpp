#include<bits/stdc++.h>
using namespace std;
/*
思路：字符串流转整数进行比较
*/
//start here
class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(int i=0;i<version1.size();++i)if(version1[i]=='.')version1[i]=' ';
        for(int i=0;i<version2.size();++i)if(version2[i]=='.')version2[i]=' ';
        stringstream inv1(version1);
        stringstream inv2(version2);
        int x;vector<int>v1,v2;
        while(inv1>>x)v1.push_back(x);
        while(inv2>>x)v2.push_back(x);
        int sz1=(int)v1.size();
        int sz2=(int)v2.size();
        if(sz1<sz2)for(int i=0;i<sz2-sz1;++i)v1.push_back(0);
        if(sz2<sz1)for(int i=0;i<sz1-sz2;++i)v2.push_back(0);
        for(int i=0;i<max(sz1,sz2);++i){
            if(v1[i]!=v2[i]){
                return v1[i]>v2[i]?1:-1;
            }
        }
        return 0;
    }
};
//

int main(){
    return 0;
}

