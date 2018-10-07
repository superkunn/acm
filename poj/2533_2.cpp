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
const int MAXN=1e3+10;
const int INF=0x3f3f3f3f;
int a[MAXN];
int dp[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)dp[i]=INF;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        *lower_bound(dp+1,dp+1+n,a[i])=a[i];
    }
    printf("%d",lower_bound(dp+1,dp+1+n,INF)-dp-1);
    return 0;
}
