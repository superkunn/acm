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
const int MAXN=1e3+10;
int n,p,k;
vector<pii> G[MAXN];
bool vis[MAXN];
int d[MAXN];
bool check(int mid){
    clr(vis,0);
    clr(d,0x3f);
    deque<int> deq;
    deq.push_front(1);
    d[1]=0;
    while(!deq.empty()){
        int u=deq.front();
        deq.pop_front();
        if(u==n)break;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<G[u].size();i++){
            pii v=G[u][i];
            if(vis[v.first])continue;
            if(v.second>mid){
                d[v.first]=min(d[v.first],d[u]+1);
                deq.push_back(v.first);
            }else{
                d[v.first]=min(d[v.first],d[u]);
                deq.push_front(v.first);
            }
        }
    }
    if(d[n]>k)return false;
    else return true;
}
int main(){
    scanf("%d%d%d",&n,&p,&k);
    rep(i,1,p){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].pb(mp(y,z));
        G[y].pb(mp(x,z));
    }
    int l=0,r=1000000,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%d",ans);
    return 0;
}
