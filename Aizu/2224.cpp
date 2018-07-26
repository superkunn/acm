#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+4;
struct DSU{
    int p[MAXN];
    void init(int n){for(int i=0;i<=n;i++)p[i]=i;}
    int findp(int x){return x==p[x]?x:p[x]=findp(p[x]);}
    void unite(int x,int y){x=findp(x);y=findp(y);p[x]=y;}
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;
int x[MAXN],y[MAXN];
struct edge{
    int u,v;
    double cost;
}es[1000000];
bool cmp(const edge &a,const edge &b){
    return a.cost>b.cost;
}
double work(int a,int b){
    return sqrt(1.0*(x[a]-x[b])*(x[a]-x[b])+1.0*(y[a]-y[b])*(y[a]-y[b]));
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    double ans=0.0;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&es[i].u,&es[i].v);
        es[i].cost=work(es[i].u,es[i].v);
        ans+=es[i].cost;
    }
    sort(es+1,es+1+m,cmp);
    dsu.init(n);
    for(int i=1;i<=m;i++){
        if(!dsu.same(es[i].u,es[i].v)){
            ans-=es[i].cost;
            dsu.unite(es[i].u,es[i].v);
        }
    }
    printf("%.3lf",ans);
    return 0;
}
