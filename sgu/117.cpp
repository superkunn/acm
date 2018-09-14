#include<bits/stdc++.h>
using namespace std;
int pow_mod(int a,int b,int m){
    int res=1;
    while(b){
        if(b&1)res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int ans=0;
    for(int i=1;i<=n;i++){
        int w;
        scanf("%d",&w);
        int now=pow_mod(w,m,k);
        if(now==0)ans++;
    }
    printf("%d",ans);
    return 0;
}
