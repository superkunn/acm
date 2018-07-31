#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+5;
int n,m,p,k,q,r,mod;
int a[MAXN];
inline int work(long long x,long long y,int mod){
    return x*y%mod;
}
int q1[MAXN];
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&mod);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[n-i+1]);
        }
        for(int i=k+1;i<=n;i++){
            a[n-i+1]=((work(a[n-i+2],p,mod)+work(q,i,mod))%mod+r)%mod;
        }
        int s1=0,t1=0;
        long long ans1=0;
        long long ans2=0;
        int index=n+1;
        for(int i=1;i<=n;i++){
            index--;
            while(s1!=t1&&i-q1[s1]+1>m)s1++;
            while(s1!=t1&&a[q1[t1-1]]<=a[i])t1--;
            if(s1==t1){
                q1[t1++]=i;
                if(i<m)continue;
                ans1+=a[q1[s1]]^index;
                ans2+=(t1-s1)^index;
                continue;
            }
            if(a[q1[t1-1]]>a[i])q1[t1++]=i;
            if(i<m)continue;
            ans1+=a[q1[s1]]^index;
            ans2+=(t1-s1)^index;
        }
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
