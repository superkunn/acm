#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
char op[5];
deque<pii> deq[14];
int cnt[14];
int main(){
    rep(i,1,13){
        rep(j,1,4){
            scanf("%s",op);
            if(op[0]=='A'){
                deq[i].push_back(mp(1,0));
            }else if(op[0]=='J'){
                deq[i].push_back(mp(11,0));
            }else if(op[0]=='Q'){
                deq[i].push_back(mp(12,0));
            }else if(op[0]=='K'){
                deq[i].push_back(mp(13,0));
            }else if(op[0]=='0'){
                deq[i].push_back(mp(10,0));
            }else{
                deq[i].push_back(mp(op[0]-'0',0));
            }
        }
    }
    while(deq[13].size()!=0){
        int now=deq[13].front().first;
        deq[13].pop_front();
        while(now!=13){
           // cout<<now<<endl;
            deq[now].push_front(mp(now,1));
            int t=deq[now].back().first;
            deq[now].pop_back();
            now=t;
        }
    }
    int ans=0;
    rep(i,1,12){
        while(!deq[i].empty()){
            if(deq[i].front().second==1){
                cnt[deq[i].front().first]++;
            }
            deq[i].pop_front();
        }
    }
    rep(i,1,12){
        if(cnt[i]==4)ans++;
    }
    printf("%d",ans);
    return 0;
}
