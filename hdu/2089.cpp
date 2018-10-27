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
const int MAXN=10;
int dp[MAXN][3];
void init(){
    dp[0][0]=1;
    dp[0][1]=dp[0][2]=0;
    for(int i=1;i<10;i++){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];
    }
}
int bt[MAXN];
int fun(int x){
    int ans=0;
    int len=0;
    int xx=x;
    while(xx){
        bt[++len]=xx%10;
        xx/=10;
    }
    bt[len+1]=0;
    bool flag=false;
    for(int i=len;i>=1;i--){
        ans+=bt[i]*dp[i-1][2];
        if(flag){
            ans+=bt[i]*dp[i-1][0];
        }else{
            if(bt[i]>4){
                ans+=dp[i-1][0];
            }
            if(bt[i]>6){
                ans+=dp[i-1][1];
            }
            if(bt[i+1]==6&&bt[i]>2){
                ans+=dp[i][1];
            }
        }
        if(bt[i]==4||(bt[i+1]==6&&bt[i]==2))flag=true;
    }
    if(flag)ans++;
    return x-ans;
}
int main(){
    init();
    int n,m;
    while(scanf("%d%d",&n,&m),n+m){
        printf("%d\n",fun(m)-fun(n-1));
    }
    return 0;
}
