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
const int MOD=1e9+7;
ll dp[105][10][2];
char s[105];
int bt[105];
ll dfs(int pos,int pre,int tp,bool limit,bool lead){
    if(pos==0)return 1;
    if(!limit&&!lead&&dp[pos][pre][tp]!=-1)return dp[pos][pre][tp];
    int u=limit?bt[pos]:9;
    ll res=0;
    rep(i,0,u){
        if(lead){
            if(i==0){
                res+=dfs(pos-1,0,0,limit&&bt[pos]==i,true);
            }else{
                res+=dfs(pos-1,i,0,limit&&bt[pos]==i,false);
            }
        }else{
            if(tp==0){
                if(i<=pre){
                    res+=dfs(pos-1,i,0,limit&&bt[pos]==i,false);
                }else{
                    res+=dfs(pos-1,i,1,limit&&bt[pos]==i,false);
                }
            }else{
                if(i<pre)continue;
                res+=dfs(pos-1,i,1,limit&&bt[pos]==i,false);
            }
        }
        res%=MOD;
    }
    if(!limit&&!lead)dp[pos][pre][tp]=res;
    return res;
}
int main(){
    clr(dp,-1);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len=strlen(s);
        int pos=0;
        rep(i,0,len-1){
            bt[++pos]=s[len-1-i]-'0';
        }
        printf("%lld\n",(dfs(pos,0,0,true,true)+MOD-1)%MOD);
    }
    return 0;
}
