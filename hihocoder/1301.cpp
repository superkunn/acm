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
int bt[25];
ull dp[25];
ull dfs(int pos,bool limit){
    if(pos==0)return 1;
    if(!limit&&dp[pos]!=-1)return dp[pos];
    int u=limit?bt[pos]:9;
    ull res=0;
    rep(i,0,u){
        if(i==4||i==7)continue;
        res+=dfs(pos-1,limit&&bt[pos]==i);
    }
    if(!limit)dp[pos]=res;
    return res;
}
ull gao(ull x){
    ull xx=x;
    int pos=0;
    while(x){
        bt[++pos]=x%10;
        x/=10;
    }
    return xx+1-dfs(pos,true);
}
int main(){
    clr(dp,-1);
    ull k;
    cin>>k;
    ull l=1,r=6e18,ans;
    while(l<=r){
        ull mid=(l+r)>>1;
        if(gao(mid)>=k){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}
