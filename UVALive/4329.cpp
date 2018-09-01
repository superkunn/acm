#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
typedef long long ll;
const int MAXN=1e5+10;
int n;
ll c[MAXN];
int x[20005];
ll a[20005];
ll b[20005];
void update(int i,int v){
    for(;i<=n;i+=i&-i)c[i]+=v;
}
ll query(int i){
    ll res=0;
    for(;i;i-=i&-i)res+=c[i];
    return res;
}
int main(){
    int T;
    n=100000;
    scanf("%d",&T);
    while(T--){
        clr(c,0);
        int m;
        scanf("%d",&m);
        rep(i,1,m){
            scanf("%d",&x[i]);
            ll w=query(x[i]);
            ll w2=query(x[i]-1);
            update(x[i],1);
            if(i==1||i==m)continue;
            a[i]=w;
            b[i]=i-1-w2;
        }
        ll ans=0;
        clr(c,0);
        per(i,m,1){
            ll w=m-i-query(x[i]-1);
            ll w2=query(x[i]);
            update(x[i],1);
            if(i==1||i==m)continue;
            ans+=a[i]*w;
            ans+=b[i]*w2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
