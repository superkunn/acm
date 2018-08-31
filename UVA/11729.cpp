#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
const int MAXN=1e3+10;
pii p[MAXN];
bool cmp(pii x,pii y){
    return x.se>y.se;
}
int main(){
    int n;
    int kase=0;
    while(scanf("%d",&n),n){
        rep(i,1,n){
            int x,y;
            scanf("%d%d",&x,&y);
            p[i]=mp(x,y);
        }
        sort(p+1,p+1+n,cmp);
        int now=0;
        int ans=0;
        rep(i,1,n){
            now+=p[i].fi;
            ans=max(ans,now+p[i].se);
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
