#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int MAXV=1e4+5;
const int MAXE=2e4+5;
int tot;
int head[MAXV];
struct node{
    int to,d,c,next;
}edge[MAXE<<1];
int dd[MAXV];
int cc[MAXV];
queue<int> que;
bool inq[MAXV];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int d,int c){
    edge[tot].to=v;
    edge[tot].d=d;
    edge[tot].c=c;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void spfa(){
    while(!que.empty())que.pop();
    memset(dd,-1,sizeof(dd));
    memset(inq,0,sizeof(inq));
    dd[1]=0;
    que.push(1);
    inq[1]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            int d=edge[i].d;
            int c=edge[i].c;
            if(dd[v]==-1||dd[u]+d<dd[v]||dd[u]+d==dd[v]&&c<cc[v]){
                dd[v]=dd[u]+d;
                cc[v]=c;
                if(!inq[v]){
                    que.push(v);
                    inq[v]=1;
                }
            }
        }
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        init();
        while(m--){
            int u,v,d,c;
            scanf("%d%d%d%d",&u,&v,&d,&c);
            add_edge(u,v,d,c);
            add_edge(v,u,d,c);
        }
        spfa();
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=cc[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
