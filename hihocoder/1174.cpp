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
int T,N,M,u,v,cnt;
int idec[MAXN];
vi G[MAXN];
queue<int> que;
bool topsort(){
    cnt=0;
    while(!que.empty())que.pop();
    rep(i,1,N){
        if(!idec[i])que.push(i);
    }
    while(!que.empty()){
        int u=que.front();
        que.pop();
        cnt++;
        for(auto v:G[u]){
            if(--idec[v]==0){
                que.push(v);
            }
        }
    }
    if(cnt==N)return true;
    else return false;
}
int work(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        clr(idec,0);
        while(M--){
            scanf("%d%d",&u,&v);
            G[u].pb(v);
            idec[v]++;
        }
        if(topsort())puts("Correct");
        else puts("Wrong");
        rep(i,1,N)G[i].clear();
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
