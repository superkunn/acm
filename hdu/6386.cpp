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
const int MAXN=1e6+5;
const int MAXE=2e6+5;
int N,NN,M;
namespace pre{
int vis[MAXE];
int tot;
int head[MAXN];
struct Edge{
    int v,tp,id,nxt;
    Edge(){}
    Edge(int v,int tp,int id,int nxt):v(v),tp(tp),id(id),nxt(nxt){}
}edge[MAXE<<1];
void init(){
    tot=0;
    clr(vis,0);
    clr(head,-1);
}
void add_edge(int u,int v,int tp,int id){
    edge[tot]=Edge(v,tp,id,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,tp,id,head[v]);
    head[v]=tot++;
}
};
int tot;
int head[MAXE];
struct Edge{
    int v,w,nxt;
    Edge(){}
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}edge[MAXE<<2];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v,int w){
    edge[tot]=Edge(v,w,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,w,head[v]);
    head[v]=tot++;
}
void dfs(int x,int tp){
    for(int i=pre::head[x];i!=-1;i=pre::edge[i].nxt){
        int v=pre::edge[i].v;
        int id=pre::edge[i].id;
        if(!pre::vis[id]&&pre::edge[i].tp==tp){
            pre::vis[id]=1;
            add_edge(v,NN,1);
            dfs(v,tp);
        }
    }
}
queue<int> que;
bool inq[MAXE];
int d[MAXE];
int spfa(int s,int t){
    while(!que.empty())que.pop();
    clr(inq,0);
    clr(d,-1);
    d[s]=0;
    que.push(s);
    inq[s]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            int w=edge[i].w;
            if(d[v]==-1||d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!inq[v]){
                    que.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    if(d[t]==-1)return -1;
    else return d[t]/2;
}
int work(){
    while(scanf("%d%d",&N,&M)!=EOF){
        pre::init();
        rep(i,1,M){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            pre::add_edge(a,b,c,i);
        }
        init();
        NN=N;
        rep(i,1,N){
            for(int j=pre::head[i];j!=-1;j=pre::edge[j].nxt){
                int id=pre::edge[j].id;
                if(!pre::vis[id]){
                    NN++;
                    add_edge(i,NN,1);
                    dfs(i,pre::edge[j].tp);
                }
            }
        }
        printf("%d\n",spfa(1,N));
    }
    return 0;
}

int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
