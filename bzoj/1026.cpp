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
int bt[22];
ll dp[22][10];
ll dfs(int pos,int pre,bool limit,bool lead){
    if(pos==0)return 1;
    if(!limit&&!lead&&dp[pos][pre]!=-1)return dp[pos][pre];
    int u=limit?bt[pos]:9;
    ll res=0;
    rep(i,0,u){
        if(lead){
            res+=dfs(pos-1,i,limit&&i==bt[pos],lead&&i==0);
        }else{
            if(abs(pre-i)<2)continue;
            res+=dfs(pos-1,i,limit&&i==bt[pos],false);
        }
    }
    if(!limit&&!lead)dp[pos][pre]=res;
    return res;
}
ll gao(ll x){
    int pos=0;
    while(x){
        bt[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,true,true);
}
int main(){
    clr(dp,-1);
    ll x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld",gao(y)-gao(x-1));
    return 0;
}
