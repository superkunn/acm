#include<bits/stdc++.h>
using namespace std;
const int MAXV=1e6+5;
const int MAXE=4e6+5;
const int INF=1e9;
int tot;
int head[MAXV];
int iter[MAXV];
int level[MAXV];
struct node{
    int to,cap,rev,next;
};
node edge[2*MAXE];// two times!!!
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int a,int b,int c){
    edge[tot].to=b;
    edge[tot].cap=c;
    edge[tot].rev=tot+1;
    edge[tot].next=head[a];
    head[a]=tot++;

    edge[tot].to=a;
    edge[tot].cap=c;
    edge[tot].rev=tot-1;
    edge[tot].next=head[b];
    head[b]=tot++;
}
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v=que.front();que.pop();
        for(int i=head[v];i!=-1;i=edge[i].next){
            node &e=edge[i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f){
    if(v==t)return f;
    for(int &i=iter[v];i!=-1;i=edge[i].next){
        node &e = edge[i];
        if(e.cap>0&&level[v]<level[e.to]){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                edge[e.rev].cap+=d;
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
        for(int i=0;i<MAXV;i++){
            iter[i]=head[i];
        }
        int f;
        while((f=dfs(s,t,INF))>0){
            flow+=f;
        }
    }
}
int main(){
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            int w;
            scanf("%d",&w);
            int x=(i-1)*m+j;
            int y=(i-1)*m+j+1;
            add_edge(x,y,w);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            int w;
            scanf("%d",&w);
            add_edge((i-1)*m+j,i*m+j,w);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int w;
            scanf("%d",&w);
            add_edge((i-1)*m+j,i*m+j+1,w);
        }
    }
    int s=0;
    int t=n*m+1;
    add_edge(s,1,INF);
    add_edge(n*m,t,INF);
    printf("%d\n",max_flow(s,t));
    return 0;
}
