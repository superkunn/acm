#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
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
typedef vector<long long> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<vvvvl> vvvvvl;
int a[6];
vvvvvl dp;
ll dfs(int x1,int x2,int x3,int x4,int x5){
    if(dp[x1][x2][x3][x4][x5]!=0)return dp[x1][x2][x3][x4][x5];
    if(x1!=0&&x1-1>=x2){
        dp[x1][x2][x3][x4][x5]+=dfs(x1-1,x2,x3,x4,x5);
    }
    if(x2!=0&&x2-1>=x3){
        dp[x1][x2][x3][x4][x5]+=dfs(x1,x2-1,x3,x4,x5);
    }
    if(x3!=0&&x3-1>=x4){
        dp[x1][x2][x3][x4][x5]+=dfs(x1,x2,x3-1,x4,x5);
    }
    if(x4!=0&&x4-1>=x5){
        dp[x1][x2][x3][x4][x5]+=dfs(x1,x2,x3,x4-1,x5);
    }
    if(x5!=0){
        dp[x1][x2][x3][x4][x5]+=dfs(x1,x2,x3,x4,x5-1);
    }
    return dp[x1][x2][x3][x4][x5];
}
int main(){
    int n;
    while(scanf("%d",&n),n){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dp.clear();
        for(int i1=0;i1<=a[1];i1++){
            vvvvl v4;
            for(int i2=0;i2<=a[2];i2++){
                vvvl v3;
                for(int i3=0;i3<=a[3];i3++){
                    vvl v2;
                    for(int i4=0;i4<=a[4];i4++){
                        vl now;
                        for(int i5=0;i5<=a[5];i5++){
                            now.push_back(0LL);
                        }
                        v2.push_back(now);
                    }
                    v3.push_back(v2);
                }
                v4.push_back(v3);
            }
            dp.push_back(v4);
        }
        dp[0][0][0][0][0]=1;
        printf("%lld\n",dfs(a[1],a[2],a[3],a[4],a[5]));
    }
    return 0;
}
