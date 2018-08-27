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
vector<pii> vec;
bool cmp(pii x,pii y){
    return y.fi-x.se>x.fi-y.se;
}
int work(){
    int N;
    scanf("%d",&N);
    rep(i,1,N){
        int x,y;
        scanf("%d%d",&x,&y);
        vec.pb(mp(x,y));
    }
    sort(all(vec),cmp);
    ll ans=-vec[0].se;
    ll sum=vec[0].fi;
    rep(i,1,N-1){
        ans=max(ans,sum-vec[i].se);
        sum+=vec[i].fi;
    }
    printf("%lld",ans);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
