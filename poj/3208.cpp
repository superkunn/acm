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
ll dp[25][4];
void init(){
    dp[0][0]=1;
    dp[0][1]=dp[0][2]=dp[0][3]=0;
    for(int i=1;i<20;i++){
        dp[i][0]=9*(dp[i-1][0]+dp[i-1][1]+dp[i-1][2]);
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1];
        dp[i][3]=10*dp[i-1][3]+dp[i-1][2];
    }
}
int bt[30];
ll fun(ll x){
    int len=0;
    while(x){
        bt[++len]=x%10;
        x/=10;
    }
    bt[len+1]=0;
    bt[len+2]=0;
    bt[len+3]=0;
    ll ans=0;
    bool flag=false;
    for(int i=len;i>=1;i--){
        ans+=dp[i-1][3]*bt[i];
        if(flag){
            ans+=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])*bt[i];
        }else{
            if(bt[i]>6){
                ans+=dp[i-1][2];
            }
            if(bt[i+1]==6&&bt[i]>6){
                ans+=dp[i-1][1];
            }
            if(bt[i+2]==6&&bt[i+1]==6&&bt[i]>6)ans+=dp[i][1];
        }
        if(bt[i]==6&&bt[i+1]==6&&bt[i+2]==6)flag=true;
    }
    if(flag)ans++;
    return ans;
}
int main(){
    init();
//    for(int i=1;i<=5;i++){
//        for(int j=0;j<4;j++)cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
//    cout<<fun(1668)<<endl;
    int T;
    scanf("%d",&T);

    while(T--){
        int x;
        scanf("%d",&x);
        ll l=1,r=1e18,ans;
        while(l<=r){
            ll mid=(l+r)>>1;
            //cout<<mid<<endl;
            if(fun(mid)>=x){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
