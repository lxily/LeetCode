#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N=gas.size();
        for(int i=0;i<N;i++)gas[i]-=cost[i];
        gas.insert(gas.end(),gas.begin(),gas.end());
        int sum=0,l=0;
        for(int r=0;r<N*2;r++){
            sum+=gas[r];
            if(sum<0){
                sum=0;l=r+1;
            }
            else if(r-l+1==N){
                return r%N;
            }
        }
        return -1;
    }
};
int main(){
    return 0;
}
