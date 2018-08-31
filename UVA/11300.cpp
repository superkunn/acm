#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const int MAXN=1e6+10;
ll a[MAXN];
int main(){
    int n;
    while(~scanf("%d",&n)){
        ll sum=0;
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            sum+=x;
            if(i!=n){
                a[i+1]=a[i]+x;
            }
        }
        ll w=sum/n;
        rep(i,2,n){
            a[i]-=(i-1)*w;
        }
        sort(a+1,a+1+n);
        ll a1=a[(1+n)/2];
        ll ans=0;
        rep(i,1,n){
            ans+=abs(a1-a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
