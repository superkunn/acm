//Cities
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        ll ans=0;
        int mi=1e6;
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            ans+=x;
            mi=min(mi,x);
        }
        ans-=mi;
        ans+=1LL*mi*(n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
