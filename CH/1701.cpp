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
priority_queue<ll> pque;
int main(){
    int n;
    scanf("%d",&n);
    int x;
    rep(i,1,n)scanf("%d",&x),pque.push(-x);
    ll ans=0;
    while(pque.size()!=1){
        ll x=pque.top();
        pque.pop();
        ll y=pque.top();
        pque.pop();
        ans-=x+y;
        pque.push(x+y);
    }
    printf("%I64d",ans);
    return 0;
}
