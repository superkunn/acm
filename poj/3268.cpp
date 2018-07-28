#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int MAXV=1e3+5;
const int MAXE=1e5+5;
int tot;
int head[MAXV];
struct node{
    int to,cost,next;
}edge[MAXE];
int ex[MAXE],ey[MAXE],ew[MAXE];
int d1[MAXV];
int d2[MAXV];
queue<int> que;
bool inq[MAXV];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w){
    edge[tot].to=v;
    edge[tot].cost=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void spfa(int *d,int x){
    while(!que.empty())que.pop();
    memset(inq,0,sizeof(inq));
    d[x]=0;
    que.push(x);
    inq[x]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            int w=edge[i].cost;
            if(d[v]==-1||d[u]+w<d[v]){
                d[v]=d[u]+w;
                if(!inq[v]){
                    que.push(v);
                    inq[v]=1;
                }
            }
        }
    }
}
int main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    init();
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&ex[i],&ey[i],&ew[i]);
        add_edge(ex[i],ey[i],ew[i]);
    }
    memset(d1,-1,sizeof(d1));
    spfa(d1,x);
    init();
    for(int i=1;i<=m;i++){
        add_edge(ey[i],ex[i],ew[i]);
    }
    memset(d2,-1,sizeof(d2));
    spfa(d2,x);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,d1[i]+d2[i]);
    }
    printf("%d\n",ans);
    return 0;
}
