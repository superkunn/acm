#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=1e5+10;
vi G[MAXN];
int tp[MAXN];
int ans;
void dfs(int u){
    for(auto v:G[u]){
        if(tp[v]!=-1){
            if(tp[v]==tp[u])ans=1;
        }else{
            tp[v]=tp[u]^1;
            dfs(v);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].pb(y);
        G[y].pb(x);
    }
    clr(tp,-1);
    ans=0;
    tp[1]=1;
    dfs(1);
    if(ans==0){
        puts("2");
    }else{
        puts("3");
    }
    return 0;
}
