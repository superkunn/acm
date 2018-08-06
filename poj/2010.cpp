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
const int MAXN=1e5+5;
int N,C;
ll F;
ll lsum[MAXN],rsum[MAXN];
pii cow[MAXN];
priority_queue<ll> que;
int mx,b;
ll sum;
int work(){
    scanf("%d%d%lld",&N,&C,&F);
    rep(i,1,C)scanf("%d%d",&cow[i].fi,&cow[i].se);
    sort(cow+1,cow+1+C);
    b=N/2;
    memset(lsum,0,sizeof(lsum));
    memset(rsum,0,sizeof(rsum));
    while(!que.empty())que.pop();
    mx=0;
    sum=0;
    rep(i,1,b){
        mx=max(mx,cow[i].se);
        que.push(cow[i].se);
        sum+=cow[i].se;
    }
    lsum[b]=sum;
    rep(i,b+1,C-b-1){
        if(cow[i].se<mx){
            sum-=mx;
            que.pop();
            sum+=cow[i].se;
            que.push(cow[i].se);
            mx=que.top();
        }
        lsum[i]=sum;
    }
    while(!que.empty())que.pop();
    mx=0;
    sum=0;
    per(i,C,C-b+1){
        mx=max(mx,cow[i].se);
        que.push(cow[i].se);
        sum+=cow[i].se;
    }
    rsum[C-b+1]=sum;
    per(i,C-b,b+2){
        if(cow[i].se<mx){
            sum-=mx;
            que.pop();
            sum+=cow[i].se;
            que.push(cow[i].se);
            mx=que.top();
        }
        rsum[i]=sum;
    }
    int ans=-1;
    rep(i,b+1,C-b){
        if(lsum[i-1]+rsum[i+1]+cow[i].se<=F){
            ans=max(ans,cow[i].fi);
        }
    }
    printf("%d\n",ans);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
