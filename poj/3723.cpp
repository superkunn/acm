#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXE=5e4+50;
const int MAXN=2e4+50;
struct DSU{
    int p[MAXN],r[MAXN];
    void init(int x){
        for(int i=0;i<=x;i++){
            p[i]=i;
            r[i]=0;
        }
    }
    int findp(int x){
        if(x==p[x])return x;
        else return p[x]=findp(p[x]);
    }
    void unite(int x,int y){
        x=findp(x);
        y=findp(y);
        if(x==y)return;
        if(r[x]<r[y]){
            p[x]=y;
        }
        else{
            p[y]=x;
            if(r[x]==r[y])r[x]++;
        }
    }
    bool same(int x,int y){
        return findp(x)==findp(y);
    }
}dsu;
int V,E;
struct edge{int u,v,cost;}es[MAXE];
bool cmp(const edge &e1,const edge &e2){
    return e1.cost<e2.cost;
}
int kruskal(){
    sort(es,es+E,cmp);
    dsu.init(V);
    int res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!dsu.same(e.u,e.v)){
            dsu.unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}
int main(){
    int w;
    scanf("%d",&w);
    while(w--){
        int N,M;
        scanf("%d%d%d",&N,&M,&E);
        V=N+M;
        for(int i=0;i<E;i++){
            scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
            es[i].v+=N;
            es[i].cost=-es[i].cost;
        }
        printf("%lld\n",1LL*10000*(N+M)+kruskal());
    }
    return 0;
}
