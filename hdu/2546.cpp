#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
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
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=1100;
int n,m;
int a[MAXN],dp[MAXN];
int work(){
    while(~scanf("%d",&n)){
        if(n==0)break;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int mxid;
        int mx=0;
        rep(i,1,n){
            scanf("%d",&a[i]);
            if(a[i]>mx){
                mx=a[i];
                mxid=i; 
            }
        }
        scanf("%d",&m);
        if(m<5){
            printf("%d\n",m);
            continue;
        }
        if(mx<5){
            rep(i,1,n){
                per(j,m,0){
                    if(j+a[i]<=m&&dp[j])dp[j+a[i]]=1;
                }
            }
            per(i,m,0){
                if(dp[i]){
                    printf("%d\n",m-i);
                    break;
                }
            }
            continue;
        }
        rep(i,1,n){
            if(i==mxid)continue;
            per(j,m-5,0){
                if(j+a[i]<=m-5&&dp[j])dp[j+a[i]]=1;
            }
        }
        int ans=mx;
        per(i,m-5,0){
            if(dp[i]){
                ans+=i;
                break;
            }
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
