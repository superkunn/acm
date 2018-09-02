#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define mp make_pair
typedef pair<int,int> pii;
const int MAXN=1e3+10;
queue<pii > que;
int u[MAXN],v[MAXN];
int dc[55];
int tot;
int head[55];
struct Edge{
    int v,vis,nxt;
    Edge(){}
    Edge(int v,int vis,int nxt):v(v),vis(vis),nxt(nxt){}
}edge[MAXN<<1];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,0,head[u]);
    head[u]=tot++;
}
void dfs(int u){
    for(int i=head[u];~i;i=edge[i].nxt){
        if(!edge[i].vis){
            edge[i].vis=1;
            edge[i^1].vis=1;
            dfs(edge[i].v);
            que.push(mp(u,edge[i].v));
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    bool f=1;
    rep(kase,1,T){
        if(f)f=0;
        else puts("");
        int n;
        scanf("%d",&n);
        clr(dc,0);
        init();
        rep(i,1,n){
            scanf("%d%d",&u[i],&v[i]);
            dc[u[i]]++;
            dc[v[i]]++;
            add_edge(u[i],v[i]);
            add_edge(v[i],u[i]);
        }
        bool flag=0;
        rep(i,1,50){
            if((dc[i]%2)==1){
                flag=1;
                break;
            }
        }
        printf("Case #%d\n",kase);
        if(flag){
            puts("some beads may be lost");
        }else{
            while(!que.empty())que.pop();
            dfs(u[1]);
            if(que.size()!=n){
                puts("some beads may be lost");
            }else{
                while(!que.empty()){
                    printf("%d %d\n",que.front().second,que.front().first);
                    que.pop();
                }
            }
        }
    }
    return 0;
}
