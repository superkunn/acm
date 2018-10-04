#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
int a[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int w=a[n/2+1];
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=abs(a[i]-w);
    printf("%lld",ans);
    return 0;
}
