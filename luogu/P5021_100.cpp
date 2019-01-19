#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
inline int gi() {
    register int data = 0, w = 1;
    register char ch = 0;
    while (ch != '-' && (ch > '9' || ch < '0')) ch = getchar();
    if (ch == '-') w = -1 , ch = getchar();
    while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
    return w * data;
}
#define MAXN 50005
multiset<int> now;
multiset<int> :: iterator it;
int n,m,mid;
int tot;
int head[MAXN];
struct Edge{
    int v,w,nxt;
}edge[MAXN<<1];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w){
    edge[tot]=Edge{v,w,head[u]};
    head[u]=tot++;
}
int d[MAXN],a[MAXN];
int cnt;
void dfs(int u,int p){
    int top=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        if(edge[i].v==p)continue;
        dfs(edge[i].v,u);
    }
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p)continue;
        d[v]+=edge[i].w;
        if(d[v]>=mid)cnt++;
        else{
            a[++top]=d[v];
        }
    }
    sort(a+1,a+1+top);
    now.clear();
    for(int i=1;i<=top;i++){
        it=now.lower_bound(mid-a[i]);
        if(it!=now.end()){
            cnt++;
            now.erase(it);
        }else{
            now.insert(a[i]);
        }
    }
    if(now.size()==0){
        d[u]=0;
        return;
    }
    d[u]=*now.rbegin();
}

int main(){
    init();
    n=gi(),m=gi();
    int l=0,r=0,ans=0;
    for(int i=2;i<=n;i++){
        int u,v,w;
        u=gi();
        v=gi();
        w=gi();
        add_edge(u,v,w);
        add_edge(v,u,w);
        r+=w;
    }
    r/=m;
    while(l<=r){
        mid=(l+r)>>1;
        cnt=0;
        dfs(1,-1);
        if(cnt>=m){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}

