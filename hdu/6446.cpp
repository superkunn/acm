#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=100000+10;
const int MOD=1e9+7;
ll nn[MAXN];
int uu[MAXN],vv[MAXN],ww[MAXN];
int tot;
int head[MAXN];
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):v(v),nxt(nxt){}
}edge[MAXN<<1];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
int sz[MAXN];
void dfs(int u,int p){
    sz[u]=1;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int main(){
    nn[1]=1;
    rep(i,2,100000){
        nn[i]=nn[i-1]*i;
        if(nn[i]>MOD){
            nn[i]%=MOD;
        }
    }
    int n;
    while(~scanf("%d",&n)){
        init();
        rep(i,2,n){
            scanf("%d%d%d",&uu[i],&vv[i],&ww[i]);
            add_edge(uu[i],vv[i]);
            add_edge(vv[i],uu[i]);
        }
        dfs(1,-1);
        ll ans=0;
        rep(i,2,n){
            ll a1=sz[uu[i]];
            ll a2=sz[vv[i]];
            if(a2<a1)swap(a1,a2);
            ll now=(a1*(n-a1))%MOD;
            now=(now*nn[n-1])%MOD;
            now=(now*ww[i])%MOD;
            ans=(ans+now)%MOD;
        }
        ans=(ans*2)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
