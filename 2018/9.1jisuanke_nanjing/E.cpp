#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const int MAXN=20+5;
ll a[MAXN],b[MAXN];
int s[MAXN];
int base[32];
ll dp[1<<22];
bool vis[1<<22];
void fun(int pos,int x){
    rep(i,1,x){
        int w;
        scanf("%d",&w);
        s[pos]+=base[w];
    }
}
int tt(int t){
    int res=0;
    while(t){
        if(t&1)res++;
        t>>=1;
    }
    return res;
}
bool check(int x,int y,int n){
    rep(i,1,n){
        if((s[y]&base[i])!=0){
            if((x&base[i])==0)return false;
        }
    }
    return true;
}
int main(){
    base[1]=1;
    rep(i,2,22)base[i]=base[i-1]<<1;
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        int x;
        scanf("%lld%lld%d",&a[i],&b[i],&x);
        fun(i,x);
    }
    ll ans=0;
    queue<int> que;
    rep(i,1,n){
        if(s[i]==0)dp[1<<(i-1)]=1LL*a[i]+b[i],vis[1<<(i-1)]=1,que.push(1<<(i-1));
    }
    while(!que.empty()){
        int t=que.front();
        que.pop();
        ans=max(ans,dp[t]);
        int tm=tt(t)+1;
        rep(i,1,n){
            if((t&base[i])==0){
                int nxt=t+base[i];
                if(check(t,i,n)){
                    if(!vis[nxt]){
                        dp[nxt]=dp[t]+1LL*tm*a[i]+b[i],vis[nxt]=1;
                        que.push(nxt);
                    }else{
                        dp[nxt]=max(dp[nxt],dp[t]+1LL*tm*a[i]+b[i]);
                    }
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
