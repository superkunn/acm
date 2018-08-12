#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <cstdio>
#include    <vector>
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
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=5e4+10;
const int INF=0x3f3f3f3f;
int n;
int c,t,d[MAXN];
int tot;
int head[MAXN];
struct Edge{
    int v,w,nxt;
    Edge(){}
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}edge[MAXN<<2];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v,int w){
    edge[tot]=Edge(v,w,head[u]);
    head[u]=tot++;
}
queue<int> que;
bool inq[MAXN];
int spfa(){
    while(!que.empty())que.pop();
    rep(i,1,t+c)d[i]=INF;
    clr(inq,0);
    d[t+c]=0;
    que.push(t+c);
    inq[t+c]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            int w=edge[i].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!inq[v]){
                    que.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    return d[-1+c];
}
int work(){
    scanf("%d",&n);
    c=2;
    t=MAXN-2;
    init();
    while(n--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(y+c,x-1+c,-z);
    }
    rep(i,-1,t-1){
        add_edge(i+c,i+1+c,1);
        add_edge(i+1+c,i+c,0);
    }
    printf("%d",-spfa());
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
