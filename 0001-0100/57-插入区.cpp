#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        #define inf 0x3f3f3f3f
        vector<vector<int>>ret;
        if(!intervals.size()&&!newInterval.size())
            return {};
        else if(!intervals.size()){
            ret.push_back(newInterval);
            return ret;
        }
        else if(!newInterval.size())
            return intervals;
        if(newInterval[0]<=intervals[0][0]){
            ret.push_back(newInterval);
            newInterval[0]=newInterval[1]=inf;
        }
        for(int i=0;i<intervals.size();i++){
            if(!ret.size()){
                ret.push_back(intervals[i]);
                continue;
            }
            if(newInterval[0]<=intervals[i][0]){
                if(newInterval[0]>ret[ret.size()-1][1]){
                    ret.push_back(newInterval);
                }
                else if(ret[ret.size()-1][1]<newInterval[1]){
                    ret[ret.size()-1][1]=newInterval[1];
                }
                newInterval[0]=newInterval[1]=inf;
            }
            if(intervals[i][0]>ret[ret.size()-1][1]){
                ret.push_back(intervals[i]);
            }
            else if(ret[ret.size()-1][1]<intervals[i][1]){
                ret[ret.size()-1][1]=intervals[i][1];
            }
        }
        if(newInterval[0]!=inf){
            if(newInterval[0]>ret[ret.size()-1][1]){
                ret.push_back(newInterval);
            }
            else if(ret[ret.size()-1][1]<newInterval[1]){
                ret[ret.size()-1][1]=newInterval[1];
            }
        }
        return ret;
    }
};
int main(){
    return 0;
}
