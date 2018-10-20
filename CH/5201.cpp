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
const int MAXN=2e4+10;
int dp[MAXN];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(int j=m;j>=0;j--){
            dp[j+x]+=dp[j];
        }
    }
    printf("%d",dp[m]);
    return 0;
}
