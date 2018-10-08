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
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
int n;
const int MAXN=2e5+10;
int a[MAXN];
int dp1[MAXN];
int dp2[MAXN];
struct BIT{
    int n;
    int c[MAXN];
    void init(int _n){
        n=_n;
        memset(c,0,sizeof(c));
    }
    void update(int i,int v){
        for(;i<=n;i+=i&-i){
            c[i]+=v;
        }
    }
    int query(int i){
        int s=0;
        for(;i;i-=i&-i){
            s+=c[i];
        }
        return s;
    }
}bit;
int main(){
    scanf("%d",&n);
    bit.init(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp1[i]=bit.query(a[i]);
        bit.update(a[i],1);
    }
    bit.init(n);
    for(int i=n;i>=1;i--){
        dp2[i]=bit.query(a[i]);
        bit.update(a[i],1);
    }
//    for(int i=1;i<=n;i++)printf("%d%c",dp1[i]," \n"[i==n]);
//    for(int i=1;i<=n;i++)printf("%d%c",dp2[i]," \n"[i==n]);
    ll ans1=0,ans2=0;
    for(int i=2;i+1<=n;i++){
        ans1+=1LL*(i-1-dp1[i])*(n-i-dp2[i]);
        ans2+=1LL*dp1[i]*dp2[i];
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}
