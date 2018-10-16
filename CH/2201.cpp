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
const int INF=0x3f3f3f3f;
vi v;
int ans,n,w;
int ww[20];
void dfs(int now,int cnt){
    if(cnt>=ans){
        return;
    }
    if(now==n+1){
        ans=min(ans,cnt);
        return;
    }
    for(int i=0;i<cnt;i++){
        if(ww[i]+v[now-1]<=w){
            ww[i]+=v[now-1];
            dfs(now+1,cnt);
            ww[i]-=v[now-1];
        }
    }
    ww[cnt]=v[now-1];
    dfs(now+1,cnt+1);
    ww[cnt]=0;
}
int main(){
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.pb(x);
    }
    sort(v.rbegin(),v.rend());
    ans=INF;
    dfs(1,0);
    printf("%d",ans);
    return 0;
}
