#include<bits/stdc++.h>
using namespace std;
const int MAXV=55;
const int MAXE=5500;
int vis[MAXV];
int tot;
int head[MAXV];
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):v(v),nxt(nxt){}
}edge[MAXE];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
int main(){
    int n,st;
    scanf("%d%d",&n,&st);
    init();
    for(int i=1;i<=n;i++){
        int m;
        scanf("%d",&m);
        for(int j=1;j<=m;j++){
            int w;
            scanf("%d",&w);
            add_edge(i,w);
        }
    }
    queue<int> que;
    memset(vis,-1,sizeof(vis));
    que.push(st);
    vis[st]=0;
    vector<int> ans;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        if(vis[u]==2){
            ans.push_back(u);
            continue;
        }
        for(int i=head[u];~i;i=edge[i].nxt){
            int v=edge[i].v;
            if(vis[v]==-1){
                vis[v]=vis[u]+1;
                que.push(v);
            }
        }
    }
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
