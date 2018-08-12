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
const int MAXN=30;
int n,m,cnt;
char op[5];
bool vis[MAXN];
int idec[MAXN],cur[MAXN],mmp[MAXN][MAXN];
bool flag;
int st,ed;
int que[MAXN];
vi G[MAXN];
void init(){
    rep(i,0,25)G[i].clear();
}
int topsort(){
    st=1,ed=0;
    bool f=1;
    rep(i,0,n-1){
        if(!vis[i])continue;
        cur[i]=idec[i];
        if(!cur[i])que[++ed]=i;
    }
    while(st<=ed){
        int u=que[st++];
        for(int i=0;i<(int)G[u].size();i++){
            int v=G[u][i];
            if(--cur[v]==0)que[++ed]=v;
        }
    }
    rep(i,2,ed){
        if(!mmp[que[i-1]][que[i]]){
            f=0;
            break;
        }
    };
    if(ed==n&&f)return 1;
    else if(ed!=cnt) return -1;
    else return 0;
}
int work(){
    while(scanf("%d%d",&n,&m),n+m){
        flag=0;
        cnt=0;
        clr(vis,0);
        clr(idec,0);
        clr(mmp,0);
        init();
        rep(i,1,m){
            scanf("%s",op);
            if(flag)continue;
            int u=op[0]-'A';
            int v=op[2]-'A';
            mmp[u][v]=1;
            if(!vis[u]){
                cnt++;
                vis[u]=true;
            }
            if(!vis[v]){
                cnt++;
                vis[v]=true;
            }
            G[u].pb(v);
            idec[v]++;
            if(topsort()==1){
                flag=1;
                printf("Sorted sequence determined after %d relations: ",i);
                rep(j,1,ed)putchar('A'+que[j]);
                puts(".");
            }else if(topsort()==-1){
                flag=1;
                printf("Inconsistency found after %d relations.\n",i);
            }
        }
        if(!flag)puts("Sorted sequence cannot be determined.");
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
