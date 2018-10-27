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
int bt[21];
int dp[21][2];
int dfs(int pos,int pre,bool limit){
    if(pos==0)return 1;
    if(!limit&&dp[pos][pre==6]!=-1)return dp[pos][pre==6];
    int u=limit?bt[pos]:9;
    int res=0;
    for(int i=0;i<=u;i++){
        if(i==4)continue;
        if(pre==6&&i==2)continue;
        res+=dfs(pos-1,i,limit&&i==bt[pos]);
    }
    if(!limit)dp[pos][pre==6]=res;
    return res;
}
int gao(int x){
    int pos=0;
    while(x){
        bt[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,-1,true);
}
int main(){
    int n,m;
    clr(dp,-1);
    while(scanf("%d%d",&n,&m),n+m){
        printf("%d\n",gao(m)-gao(n-1));
    }
    return 0;
}
