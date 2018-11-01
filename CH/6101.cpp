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
const int MAXV=1e5+10;
const int MAXE=1e6+10;
int n,m;
int x[MAXE>>1],y[MAXE>>1],z[MAXE>>1];
int a[MAXV];
int f[MAXV];
int d[MAXV];
int head[MAXV];
int tot;
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):
        v(v),nxt(nxt){}
}edge[MAXE];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
void dij1(){
    priority_queue<pii,vector<pii>,greater<pii> > pque;
    memset(d,0x3f,sizeof(d));
    d[1]=a[1];
    pque.push(mp(d[1],1));
    while(!pque.empty()){
        pii t=pque.top();
        pque.pop();
        int u=t.second;
        if(d[u]<t.first)continue;
        for(int i=head[u];~i;i=edge[i].nxt){
            int v=edge[i].v;
            if(d[v]>min(d[u],a[v])){
                d[v]=min(d[u],a[v]);
                pque.push(mp(d[v],v));
            }
        }
    }
}
void dij2(){
    priority_queue<pii> pque;
    memset(f,-1,sizeof(f));
    f[n]=a[n];
    pque.push(mp(f[n],n));
    while(!pque.empty()){
        pii t=pque.top();
        pque.pop();
        int u=t.second;
        if(f[u]>t.first)continue;
        for(int i=head[u];~i;i=edge[i].nxt){
            int v=edge[i].v;
            if(f[v]<max(f[u],a[v])){
                f[v]=max(f[u],a[v]);
                pque.push(mp(f[v],v));
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d",&a[i]);
    init();
    rep(i,1,m){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        if(z[i]==1){
            add_edge(x[i],y[i]);
        }else{
            add_edge(x[i],y[i]);
            add_edge(y[i],x[i]);
        }
    }
    dij1();
    init();
    rep(i,1,m){
        if(z[i]==1){
            add_edge(y[i],x[i]);
        }else{
            add_edge(x[i],y[i]);
            add_edge(y[i],x[i]);
        }
    }
    dij2();
    int ans=0;
    rep(i,1,n){
        ans=max(ans,f[i]-d[i]);
    }
    printf("%d",ans);
    return 0;
}
