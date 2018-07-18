#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
#define PB push_back
#define FT first;
#define SD second;
#define ALL(X) (X).begin(),(X).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/************long long****************/
const int MAXN=1e3+5;
const int MAXE=2e4+5;
struct DSU{
    int p[MAXN];
    void init(int n){for(int i=0;i<=n;i++)p[i]=i;}
    int findp(int x){return x==p[x]?x:p[x]=findp(p[x]);}
    void unite(int x,int y){x=findp(x);y=findp(y);if(x==y)return;if(x<y)p[y]=x;else p[x]=y;}
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;
struct edge{int u,v,cost;}es[MAXE];
bool cmp(const edge &x,const edge &y){return x.cost>y.cost;}
int V,E;
int work(){
    dsu.init(V);
    sort(es,es+E,cmp);
    int res=0;
    for(int i=0;i<E;i++){
        if(!dsu.same(es[i].u,es[i].v)){
            dsu.unite(es[i].u,es[i].v);
            res+=es[i].cost;
        }
    }
    for(int i=1;i<=V;i++)if(dsu.findp(i)!=1)return -1;
    return res;
}
void solve(){
   cin>>V>>E;
   for(int i=0;i<E;i++){
       cin>>es[i].u>>es[i].v>>es[i].cost;
   }
   cout<<work();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
