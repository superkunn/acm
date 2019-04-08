#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
typedef vector<int> vi;
const int MAXN=5e4+10;
const int INF=2147483647;
vi G[MAXN];
set<int> st[MAXN];
int ans[MAXN];
int cnt;
int temp;
void merging(int u,int v){
    for(auto w:st[v]){
        if(st[u].find(w)!=st[u].end()){
            temp=0;
        }else{
            auto it=st[u].lower_bound(w);
            if(it!=st[u].begin()){
                it--;
                temp=min(temp,abs((*it)-w));
                it++;
            }
            if(it!=st[u].end()){
                temp=min(temp,abs((*it)-w));
            }
            st[u].insert(w);
        }
    }
}
void dfs(int u){
    ans[u]=INF;
    for(auto v:G[u]){
        dfs(v);
        ans[u]=min(ans[u],ans[v]);
        temp=INF;
        if(st[u].size()>st[v].size()){
            merging(u,v);
        }else{
            merging(v,u);
            swap(st[u],st[v]);
        }
        ans[u]=min(ans[u],temp);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,2,n){
        int x;
        scanf("%d",&x);
        G[x].pb(i);
    }
    rep(i,n-m+1,n){
        int x;
        scanf("%d",&x);
        st[i].insert(x);
    }
    dfs(1);
    rep(i,1,n-m){
        printf("%d ",ans[i]);
    }
    return 0;
}
