#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define clr(a,x) memset(a,x,sizeof(a))
const int MAXV=1e5+5;
const int MAXE=1e5+5;
const int INF=0x3f3f3f3f;
int tot;
int head[MAXV],level[MAXV],iter[MAXV];
struct Edge{
    int v,cap,nxt;
    Edge(){}
    Edge(int v,int cap,int nxt):v(v),cap(cap),nxt(nxt){}
}edge[MAXE<<1];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v,int c){
    edge[tot]=Edge(v,c,head[u]);
    head[u]=tot++;
    edge[tot]=Edge(u,0,head[v]);
    head[v]=tot++;
}
void bfs(int s){
    clr(level,-1);
    level[s]=0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int i=head[u];~i;i=edge[i].nxt){
            int v=edge[i].v;
            int c=edge[i].cap;
            if(c>0&&level[v]<0){
                level[v]=level[u]+1;
                que.push(v);
            }
        }
    }
}
int dfs(int u,int t,int f){
    if(u==t)return f;
    for(int &i=iter[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        int c=edge[i].cap;
        if(c>0&&level[u]<level[v]){
            int d=dfs(v,t,min(f,c));
            if(d>0){
                edge[i].cap-=d;
                edge[i^1].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow=0;
    while(1){
        bfs(s);
        if(level[t]<0)return flow;
        int f;
        memcpy(iter,head,sizeof(head));
        while(f=dfs(s,t,INF))flow+=f;
    }
}
int main(){
    int n,m,k;
    int kase=0;
    while(~scanf("%d%d%d",&n,&m,&k)){
        int l,r;
        int s=0,t=n+m+1;
        int x=t+1;
        int y=x+1;
        scanf("%d%d",&l,&r);
        init();
        add_edge(t,s,INF);
        for(int i=1;i<=n;i++)add_edge(s,i,r-l),add_edge(s,y,l),add_edge(x,i,l);
        for(int i=1;i<=m;i++)add_edge(i+n,t,r-l),add_edge(i+n,y,l),add_edge(x,t,l);
        while(k--){
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v+n,1);
        }
        int xx=max_flow(x,y);
        bool f=1;
        for(int i=head[x];~i;i=edge[i].nxt){
            if(edge[i].cap!=0)f=0;
        }
        if(f)printf("Case %d: Yes\n",++kase);
        else printf("Case %d: No\n",++kase);
    }
    return 0;
}
