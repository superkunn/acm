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
const int MAXN=1e5+10;
ll xx[MAXN],yy[MAXN];
ll ans1[MAXN],ans2[MAXN];
struct node{
    int x,y,id;
}no[MAXN];
bool cmp1(node a,node b){
    return a.x<b.x;
}
bool cmp2(node a,node b){
    return a.y<b.y;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&no[i].x,&no[i].y);
            no[i].id=i;
        }
        sort(no+1,no+1+n,cmp1);
        for(int i=1;i<=n;i++){
            xx[i]=no[i].x+xx[i-1];
        }
        for(int i=1;i<=n;i++){
            ans1[no[i].id]=1LL*(i-1)*no[i].x-xx[i-1]+(xx[n]-xx[i])-1LL*(n-i)*no[i].x;
        }
        sort(no+1,no+1+n,cmp2);
        for(int i=1;i<=n;i++){
            yy[i]=no[i].y+yy[i-1];
        }
        ll now=1e18+10;
        for(int i=1;i<=n;i++){
            ans2[no[i].id]=1LL*(i-1)*no[i].y-yy[i-1]+(yy[n]-yy[i])-1LL*(n-i)*no[i].y;
            now=min(now,ans1[no[i].id]+ans2[no[i].id]);
        }
        printf("%lld\n",now);
    }
    return 0;
}
