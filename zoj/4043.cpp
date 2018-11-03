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
const int MAXN=2e5+10;
vector<pii > no;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        no.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            no.pb(mp(x,0));
        }
        rep(i,1,m){
            int x;
            scanf("%d",&x);
            no.pb(mp(x,1));
        }
        sort(no.begin(),no.end());
        n+=m;
        ll ans=0;
        priority_queue<ll> MoreB;
        priority_queue<ll> MoreA;
        priority_queue<ll> AB;
        rep(i,0,n-1){
            ll now=no[i].first;
            if(no[i].second==0){
                if(!MoreB.empty()){
                    ll t=MoreB.top();
                    MoreB.pop();
                    ans+=now-t;
                }else if(!AB.empty()){
                    ll t=AB.top();
                    if(now<t){
                        AB.pop();
                        ans-=t-now;
                        MoreA.push(2*now-t);
                    }else{
                        MoreA.push(now);
                    }
                }else{
                    MoreA.push(now);
                }
            }else{
                if(!MoreA.empty()){
                    ll t=MoreA.top();
                    MoreA.pop();
                    ans+=now-t;
                    AB.push(2*now-t);
                }else{
                    MoreB.push(now);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
