#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
const int MAXN=1e5+233;
struct node{
    int u,v,w;
}no[MAXN];
bool cmp(node x,node y){
    return x.w<y.w;
}
int p[MAXN];
int findp(int x){
    return x==p[x]?x:p[x]=findp(p[x]);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        p[i]=i;
    }
    rep(i,1,m){
        scanf("%d%d%d",&no[i].u,&no[i].v,&no[i].w);
    }
    sort(no+1,no+1+m,cmp);
    int ans=0;
    rep(i,1,m){
        int u=no[i].u;
        int v=no[i].v;
        int w=no[i].w;
        if(findp(u)!=findp(v)){
            p[p[u]]=p[v];
            ans=max(ans,w);
            n--;
        }
    }
    if(n!=1){
        puts("-1");
    }else{
        printf("%d",ans);
    }
    return 0;
}
