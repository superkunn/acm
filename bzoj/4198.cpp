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
priority_queue<pair<ll,int> > pque;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        ll x;
        scanf("%lld",&x);
        pque.push(mp(-x,0));
    }
    ll ans1=0;
    ll w=(n-1)%(k-1);
    if(w!=0){
        rep(i,1,(k-1)-w)pque.push(mp(0,0)),n++;
    }
    int u=(n-1)/(k-1);
    rep(i,1,u){
        int now=0;
        ll bb=0;
        rep(j,1,k){
            now=min(now,pque.top().second);
            bb+=pque.top().first;
            pque.pop();
        }
        ans1-=bb;
        pque.push(mp(bb,now-1));
    }
    printf("%lld\n%d\n",ans1,-pque.top().second);
    return 0;
}
