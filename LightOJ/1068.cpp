#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
typedef long long ll;
int bt[12];
int base[12];
int dp[12][105][105];
int k;
ll dfs(int pos,int pre1,int pre2,bool limit){
    if(pos==0){
        if(pre1==0&&pre2==0)return 1;
        else return 0;
    }
    if(!limit&&dp[pos][pre1][pre2]!=-1)return dp[pos][pre1][pre2];
    int u=limit?bt[pos]:9;
    ll res=0;
    rep(i,0,u){
        res+=dfs(pos-1,(pre1+base[pos]*i)%k,(pre2+i)%k,limit&&i==bt[pos]);
    }
    if(!limit)dp[pos][pre1][pre2]=res;
    return res;
}
ll gao(ll x){
    int pos=0;
    while(x){
        bt[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,0,true);
}
int main(){
    int T;
    scanf("%d",&T);
    rep(kase,1,T){
        memset(dp,-1,sizeof(dp));
        ll x,y;
        scanf("%lld%lld%d",&x,&y,&k);
        base[1]=1;
        rep(i,2,12){
            base[i]=(base[i-1]*10)%k;
        }
        int ans;
        if(k>=100){
            ans=0;
        }else{
            ans=gao(y)-gao(x-1);
        }
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
