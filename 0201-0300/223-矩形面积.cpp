#include<bits/stdc++.h>
using namespace std;
/*
˼·��ѡ��һ��������ɨ���ߵ�����...�����Ҫ��ܶ��������Ĳ���Ҫ��ɢ��+ɨ����+�߶���
*/
//start here
class Solution {
public:
    #define ll long long
    struct node{
        int l,r,h,tag,idx;
        bool operator < (const node & nd)const{
            return h<nd.h;
        }
    };
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<node>segment;
        segment.push_back({A,C,B, 1,0});
        segment.push_back({A,C,D,-1,0});
        segment.push_back({E,G,F, 1,1});
        segment.push_back({E,G,H,-1,1});
        sort(segment.begin(),segment.end());
        ll area=0;
        ll nowHeight=segment[0].h;
        ll nowLength=segment[0].r-segment[0].l;

        if(segment[1].tag==-1)return (C-A)*(D-B)+(G-E)*(H-F);//���ص�

        area+=1ll*nowLength*(segment[1].h-nowHeight);
        nowHeight=segment[1].h;
        if(segment[1].l>=segment[0].r||segment[1].r<=segment[0].l){//�ױ߳��Ȳ�
            nowLength+=segment[1].r-segment[1].l;
        }
        else nowLength=segment[0].r-segment[0].l+segment[1].r-segment[1].l-
                       (min(segment[1].r,segment[0].r)-max(segment[1].l,segment[0].l));

        area+=1ll*nowLength*(segment[2].h-nowHeight);
        nowHeight=segment[2].h;
        if(segment[2].idx==segment[1].idx)nowLength=segment[0].r-segment[0].l;
        else nowLength=segment[1].r-segment[1].l;

        area+=1ll*nowLength*(segment[3].h-nowHeight);

        return area;
    }
};
//

int main(){
    return 0;
}
