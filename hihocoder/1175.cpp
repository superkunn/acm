#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <cstdio>
#include    <vector>
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
const int MAXN=1e5+5;
const int MOD=142857;
int N,M,K,x,u,v;
int num[MAXN],idec[MAXN];
vi G[MAXN];
queue<int> que;
void topsort(){
    while(!que.empty())que.pop();
    rep(i,1,N)if(!idec[i])que.push(i);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(auto v:G[u]){
            num[v]=(num[u]+num[v])%MOD;
            if(--idec[v]==0)que.push(v);
        }
    }
}
int work(){
    scanf("%d%d%d",&N,&M,&K);
    rep(i,1,K){
        scanf("%d",&x);
        num[x]++;
    }
    clr(idec,0);
    while(M--){
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        idec[v]++;
    }
    topsort();
    int ans=0;
    rep(i,1,N){
        ans=(ans+num[i])%MOD;
    }
    printf("%d",ans);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
