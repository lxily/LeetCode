#include<bits/stdc++.h>
using namespace std;
/*
˼·��ͳ��5���䱶�����ֵĴ���--һ����������������˵õ�ĩβ��
*/
//start here
class Solution {
public:
    int trailingZeroes(int n) {
        int ret=0;
        for(long long d=5;d<=n; ret+=n/d,d*=5);
        return ret;
    }
};
//

int main(){
    return 0;
}

