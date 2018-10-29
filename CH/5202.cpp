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
const ll MOD=2147483648;
const int MAXN=4e3+10;
ll dp[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }
    printf("%lld",(dp[n]-1+MOD)%MOD);
    return 0;
}
