#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const int MAXN=7e6+10;
struct Edge{
    int val,x,y;
}edge[MAXN];
bool cmp(Edge a,Edge b){
    return a.val<b.val;
}
struct DSU{
    int p[305];
    void init(int n){
        rep(i,0,n){
            p[i]=i;
        }
    }
    int findp(int x){
        return x==p[x]?x:p[x]=findp(p[x]);
    }
    bool same(int x,int y){
        return findp(x)==findp(y);
    }
    void unite(int x,int y){
        x=findp(x);
        y=findp(y);
        p[x]=y;
    }
}dsu;
int main(){
    int n;
    scanf("%d",&n);
    dsu.init(n);
    int tot=0;
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        edge[++tot]=Edge{x,0,i};
    }
    rep(i,1,n){
        rep(j,1,n){
            int x;
            scanf("%d",&x);
            edge[++tot]=Edge{x,i,j};
        }
    }
    sort(edge+1,edge+1+tot,cmp);
    ll ans=0;
    rep(i,1,tot){
        int x=edge[i].x,y=edge[i].y,val=edge[i].val;
        if(!dsu.same(x,y)){
            dsu.unite(x,y);
            ans+=val;
        }
    }
    printf("%lld",ans);
    return 0;
}
