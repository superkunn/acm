#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MOD=1e9+7;
const int MAXN=1e6+10;
int base[MAXN];
int a[MAXN];
int b[MAXN];
int c[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    base[1]=2;
    rep(i,2,1000000){
        base[i]=base[i-1]<<1;
        if(base[i]>MOD)base[i]-=MOD;
    }
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        if(k==1){
            puts("2");
            continue;
        }
        int t1=(base[k]-1+MOD)%MOD;
        int t2=(base[k]-2+MOD)%MOD;
        int t3=(base[k]-3+MOD)%MOD;
        if(n==1)printf("%d\n",base[k]);
        else if(n==2)printf("%d\n",1LL*base[k]*t1%MOD);
        else{
            a[1]=base[k];
            a[2]=1LL*base[k]*t2%MOD;
            b[2]=base[k];
            c[2]=0;
            rep(i,3,n){
                a[i]=(1LL*a[i-1]*t3%MOD+1LL*b[i-1]*t2+1LL*c[i-1]*t2)%MOD;
                b[i]=(1LL*b[i-1]+1LL*a[i-1])%MOD;
                c[i]=(1LL*c[i-1]+1LL*a[i-1])%MOD;
            }
            printf("%d\n",(a[n]+b[n])%MOD);
        }
    }
    return 0;
}
