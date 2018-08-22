#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
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
int mmp[105][105];
int rmmp[105][105];
int Belong[105];
bool vis[105];
int n;
int stk[105],top,scc;
void dfs(int u){
    vis[u]=true;
    rep(i,1,n)if(mmp[u][i]){
        if(!vis[i])dfs(i);
    }
    stk[++top]=u;
}
void rdfs(int u,int k){
    vis[u]=true;
    Belong[u]=k;
    rep(i,1,n)if(rmmp[u][i]){
        if(!vis[i])rdfs(i,k);
    }
}
void kscc(int V){
    top=scc=0;
    clr(vis,0);
    rep(i,1,n)if(!vis[i])dfs(i);
    clr(vis,0);
    per(i,top,1){
        int v=stk[i];
        if(!vis[v])rdfs(v,++scc);
    }
}
int idec[105],odec[105];
int work(){
    scanf("%d",&n);
    rep(i,1,n){
        int x;
        while(scanf("%d",&x),x)mmp[i][x]=1,rmmp[x][i]=1;
    }
    kscc(n);
    if(scc==1){
        puts("1");
        puts("0");
        return 0;
    }
    rep(i,1,n){
        rep(j,1,n)if(mmp[i][j]){
            int u=Belong[i];
            int v=Belong[j];
            if(u==v)continue;
            odec[u]++;
            idec[v]++;
        }
    }
    int icnt=0;
    int ocnt=0;
    rep(i,1,scc){
        if(idec[i]==0){
            icnt++;
        }
        if(odec[i]==0){
            ocnt++;
        }
    }
    printf("%d\n%d\n",icnt,max(icnt,ocnt));
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
