#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=2e4+10;
int a[MAXN],b[MAXN];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n+m){
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,1,m)scanf("%d",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        int now=1;
        int sum=0;
        bool f=0;
        rep(i,1,n){
            rep(j,now,m){
                if(b[j]>=a[i]){
                    sum+=b[j];
                    if(i==n)f=1;
                    now=j+1;
                    break;
                }
            }
            if(now>m)break;
        }
        if(!f)puts("Loowater is doomed!");
        else printf("%d\n",sum);
    }
    return 0;
}
