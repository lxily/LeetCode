#include<bits/stdc++.h>
using namespace std;
/*
思路：思维题，前面的数字越大越好
*/
//start here
class Solution {
public:
    struct Node{
        string val;
        Node(int num){
            val=num?"":"0";
            while(num){
                val.push_back(num%10+'0');num/=10;
            }
            reverse(val.begin(),val.end());
        }
        bool operator < (const Node & Nd) const{
            return val+Nd.val>Nd.val+val;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<Node>sv;
        int allZero=0;
        for(int i=0;i<nums.size();i++){
            sv.push_back(Node(nums[i]));
            allZero+=(nums[i]==0);
        }
        sort(sv.begin(),sv.end());
        string ret="";
        for(int i=0;i<sv.size();i++)
            ret+=sv[i].val;
        return allZero==nums.size()?"0":ret;
    }
};
//

int main(){
    return 0;
}

