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
int main(){
    ll n,k,ans;
    scanf("%lld%lld",&n,&k);
    ans=n*k;
    for(ll x=1,gx;x<=n;x=gx+1){
        gx=k/x?min(k/(k/x),n):n;
        ans-=(k/x)*(x+gx)*(gx-x+1)/2;
    }
    printf("%lld",ans);
    return 0;
}
