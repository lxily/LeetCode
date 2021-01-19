#include<bits/stdc++.h>
using namespace std;
/*
思路：尺取法 O(n)
*/
//start here
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target)return {l+1,r+1};
            if(numbers[l]+numbers[r]>target)r--;
            else l++;
        }
        return {-1,-1};
    }
};
//

int main(){
    return 0;
}

