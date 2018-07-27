#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXV=1e5+50;
const int INF=1e9;
struct edge{int to,cost;};
typedef pair<int,int> P;
int V;
vector<edge> G[MAXV];
int d[MAXV];
int cnt[MAXV];
bool inque[MAXV];
queue<int> que;
bool spfa(int s){
    fill(d,d+V+1,INF);
    fill(cnt,cnt+V+1,0);
    fill(inque,inque+V+1,false);
    while(!que.empty()) que.pop();
    que.push(s);
    inque[s]=true;
    d[s]=0;
    cnt[s]=1;
    while(!que.empty()){
        int u=que.front();
        inque[u]=false;
        que.pop();
        for(int i=0;i<G[u].size();i++){
            edge e=G[u][i];
            if(d[u]+e.cost<d[e.to]){
                d[e.to]=d[u]+e.cost;
                if(!inque[e.to]){
                    if(++cnt[e.to]>V)return false;
                    inque[e.to]=true;
                    que.push(e.to);
                }
            }
        }
    }
    return true;
}
int x[5005],y[5005];
bool color1[1005];
bool color2[1005];
vector<int> G1[MAXV];
vector<int> G2[MAXV];
void dfs(int x){
    color1[x]=true;
    for(int i=0;i<G1[x].size();i++){
        if(!color1[G1[x][i]])dfs(G1[x][i]);
    }
}
void rdfs(int x){
    color2[x]=true;
    for(int i=0;i<G2[x].size();i++){
        if(!color2[G2[x][i]])rdfs(G2[x][i]);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    V=n;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]);
        G1[x[i]].push_back(y[i]);
        G2[y[i]].push_back(x[i]);
    }
    dfs(1);
    rdfs(V);
    for(int i=1;i<=m;i++){
        if(color1[x[i]]&color2[x[i]]&&color1[y[i]]&color2[y[i]]){
            G[x[i]].push_back(edge{y[i],2});
            G[y[i]].push_back(edge{x[i],-1});
        }
    }
    if(!spfa(1)){
        printf("No");
        return 0;
    }
    printf("Yes\n");
    for(int i=1;i<=m;i++){
        if(color1[x[i]]&color2[x[i]]&&color1[y[i]]&color2[y[i]]){
            printf("%d\n",d[y[i]]-d[x[i]]);
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}
