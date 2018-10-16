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
const int MAXN=3e4+10;
bitset<MAXN> bs[MAXN];
vi G[MAXN];
int cnt[MAXN];
void dfs(int u){
    for(auto v:G[u]){
        cnt[v]--;
        bs[v]|=bs[u];
        if(cnt[v]==0){
            dfs(v);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        G[y].pb(x);
        cnt[x]++;
    }
    queue<int> que;
    for(int i=1;i<=n;i++){
        bs[i].reset();
        bs[i].set(i,1);
        if(cnt[i]==0){
            que.push(i);
        }
    }
    while(!que.empty()){
        dfs(que.front());
        que.pop();
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",bs[i].count());
    }
    return 0;
}
