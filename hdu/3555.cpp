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
const int MAXN=25;
ll dp[MAXN][3];
void init(){
    dp[0][0]=1;
    dp[0][1]=dp[0][2]=0;
    for(int i=1;i<25;i++){
        dp[i][0]=10*dp[i-1][0]-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=10*dp[i-1][2]+dp[i-1][1];
    }
}
int bt[MAXN];
ll fun(ll x){
    ll ans=0;
    int len=0;
    while(x){
        bt[++len]=x%10;
        x/=10;
    }
    bt[len+1]=0;
    bool flag=false;
    for(int i=len;i>=1;i--){
        ans+=dp[i-1][2]*bt[i];
        if(flag){
            ans+=dp[i-1][0]*bt[i];
        }else{
            if(bt[i]>4)ans+=dp[i-1][1];
        }
        if(bt[i+1]==4&&bt[i]==9)flag=true;
    }
    if(flag)ans++;
    return ans;
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        ll x;
        scanf("%lld",&x);
        printf("%lld\n",fun(x));
    }
    return 0;
}
