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
const int MAXN=1e4+5;
int n;
ll ans;
pii P[MAXN];
bool cmp(pii x,pii y){
    return x.se<y.se;
}
priority_queue<int> que;
int work(){
    while(scanf("%d",&n)!=EOF){
        rep(i,1,n){
            scanf("%d%d",&P[i].fi,&P[i].se);
        }
        n++;
        P[n].fi=0;
        P[n].se=0;
        sort(P+1,P+1+n,cmp);
        int now=P[n].se;
        while(!que.empty())que.pop();
        ans=0;
        per(i,n,1){
            while(now>P[i].se){
                now--;
                if(!que.empty()){
                    ans+=que.top();
                    que.pop();
                }
            }
            que.push(P[i].fi);
        }
        printf("%lld\n",ans);
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
