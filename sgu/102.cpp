#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int k;
    scanf("%d",&k);
    int ans=k;
    int n=k;
    for(int i=2;i*i<=k;i++)if(n%i==0){
        ans=ans/i*(i-1);
        while(n%i==0)n/=i;
    }
    if(n>1)ans=ans/n*(n-1);
    printf("%d",ans);
    return 0;
}
