#include<bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a,x,sizeof(a))
int nn;
const int MAXV=10;
const int MAXE=205;
int tot=0;
int head[MAXV];
struct Edge{
    int v,nxt,vis,id;
    Edge(){}
    Edge(int v,int nxt,int vis,int id):v(v),nxt(nxt),vis(vis),id(id){}
}edge[MAXE];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v,int id){
    edge[tot]=Edge(v,head[u],0,id);
    head[u]=tot++;
    edge[tot]=Edge(u,head[v],0,id);
    head[v]=tot++;
}
queue<int> ans;
void dfs(int u){
    for(int i=head[u];~i;i=edge[i].nxt){
        if(edge[i].vis==0){
            nn--;
            edge[i].vis=1;
            edge[i^1].vis=1;
            int v=edge[i].v;
            dfs(v);
            ans.push(i^1);
        }
    }
}
int indec[MAXV];
int main(){
    int n;
    scanf("%d",&n);
    init();
    clr(indec,0);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,i);
        indec[u]++;
        indec[v]++;
    }
    int cnt=0;
    for(int i=0;i<=6;i++){
        if(indec[i]%2==1){
            cnt++;
        }
    }
    if(cnt!=0&&cnt!=2){
        puts("No solution");
        return 0;
    }
    int st;
    for(int i=0;i<=6;i++){
        if(indec[i]!=0)st=i;
        if(indec[i]%2==1)break;
    }
    nn=n;
    dfs(st);
    if(nn!=0){
        puts("No solution");
        return 0;
    }
    while(!ans.empty()){
        int w=ans.front();
        ans.pop();
        printf("%d %c\n",edge[w].id,w%2==0?'+':'-');
    }
    return 0;
}
