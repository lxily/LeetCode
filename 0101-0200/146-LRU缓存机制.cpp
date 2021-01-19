#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    #define inf 0x3f3f3f3f
    vector<int>cache;
    int nowIdx,nowCap,allCap;
    unordered_map<int,int>mp;
    unordered_map<int,int>idx;

    LRUCache(int capacity) {
        allCap=capacity;
        nowIdx=0;nowCap=0;
    }
    void findMinIdx(){
        while(nowIdx<cache.size()&&cache[nowIdx]==inf)nowIdx++;
    }
    int get(int key) {
        if(!mp.count(key))return -1;
        cache.push_back(key);
        cache[idx[key]]=inf;
        idx[key]=cache.size()-1;
        findMinIdx();
        return mp[key];
    }

    void put(int key, int value) {
        if(mp.count(key)&&value!=mp[key]){
            cache.push_back(key);
            cache[idx[key]]=inf;
            idx[key]=cache.size()-1;
            findMinIdx();mp[key]=value;
            return;
        }
        if(nowCap==allCap){
            nowCap--;
            int Key=cache[nowIdx];
            cache[nowIdx]=inf;
            mp.erase(Key);
            idx.erase(Key);
            findMinIdx();
        }
        nowCap++;
        mp[key]=value;
        cache.push_back(key);
        idx[key]=cache.size()-1;
    }
};
int main(){
    return 0;
}
