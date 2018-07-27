#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
struct DSU{
    int p[MAXN];
    void init(int n){for(int i=0;i<=n;i++)p[i]=i;}
    int findp(int x){return x==p[x]?x:p[x]=findp(p[x]);}
    void unite(int x,int y){x=findp(x);y=findp(y);p[x]=y;}
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;
struct edge{
    int u,v,cost;
}es[10005];
bool cmp(const edge &a,const edge &b){
    return a.cost<b.cost;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    dsu.init(n);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
    }
    sort(es+1,es+1+m,cmp);
    int ans=0;
    for(int i=1;i<=m;i++){
        if(!dsu.same(es[i].u,es[i].v)){
            dsu.unite(es[i].u,es[i].v);
            ans=max(ans,es[i].cost);
        }
    }
    printf("%d",ans);
    return 0;
}
