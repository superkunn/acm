#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e5+10;
int n,m;
int tot;
int head[MAXN];
struct Edge{
    int v,w,nxt;
    Edge(){}
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}edge[MAXN];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w){
    edge[tot]=Edge(v,w,head[u]);
    head[u]=tot++;
}
int d[MAXN];
int cnt;
void dfs(int u,int p,int mid){
    multiset<int> now;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        int w=edge[i].w;
        if(v==p)continue;
        dfs(v,u,mid);
        if(d[v]+w>=mid)cnt++;
        else now.insert(d[v]+w);
    }
    int res=0;
    while(!now.empty()){
        auto it=now.begin();
        int cur=*it;
        now.erase(it);
        it=now.lower_bound(mid-cur);
        if(it!=now.end()){
            cnt++;
            now.erase(it);
        }else{
            res=cur;
        }
    }
    d[u]+=res;
}

bool check(int mid){
    cnt=0;
    memset(d,0,sizeof(d));
    dfs(1,-1,mid);
    if(cnt>=m)return true;
    else return false;
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    rep(i,2,n){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}

